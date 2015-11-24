
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <iostream.h>
#include <math.h>



// jacobi support functions ----------------------------------------------------------

#define NR_END 1
#define FREE_ARG char*

#define ROTATE(a,i,j,k,l) g=a[i][j];h=a[k][l];a[i][j]=g-s*(h+g*tau);a[k][l]=h+s*(g-h*tau);


void nrerror(char error_text[])
{
	// error handling code here
}

float *vector(long n1, long nh)
/* allocate a float vector with subscript range v[n1..nh] */
{
	float *v;

	v=(float *)malloc((size_t) ((nh-n1+1+NR_END)*sizeof(float)));
	if (!v) nrerror("allocation failure in vector()");
	return v-n1+NR_END;
}

void free_vector(float *v, long n1, long nh)
/* free a float vector allocated with vector() */
{
	free((FREE_ARG)(v+n1-NR_END));
}

float **matrix(long nr1, long nrh, long nc1, long nch)
/* allocate a float matrix with subscript range m[nr1..nrh][nc1..nch] */
{
	long i, nrow=nrh-nr1+1,ncol=nch-nc1+1;
	float **m;

	/* allocate pointers to rows */
	m=(float **) malloc((size_t)((nrow+NR_END)*sizeof(float*)));
	if (!m) nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nr1;

	/* allocate rows and set pointers to them */
	m[nr1]=(float *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(float)));
	if (!m[nr1]) nrerror("allocation failure 2 in matrix()");
	m[nr1] += NR_END;
	m[nr1] -= nc1;

	for(i=nr1+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
	
	/* return pointer to array of pointers of rows */
	return m;
}

void free_matrix(float **m, long nr1, long nrh, long nc1, long nch)
/* free a float matrix allocated by matrix() */
{
	free((FREE_ARG) (m[nr1]+nc1-NR_END));
	free((FREE_ARG) (m+nr1-NR_END));
}


// end of jacobi support functions ---------------------------------------------------


void jacobi(float **a, int n, float d[], float **v, int *nrot)
// Calculates the eigenvalues and eigenvectors of a real symmetric matrix.
//
// a is the input matrix, elements above diagonal are destroyed
// n is the matrix dimension
// d contains the eigenvalues
// v contains the eigenvectors
// nrot contains the number of jacobian rotations
// 
// Reproduced from "Numerical Recipes in C", Second Edition
// (Cambridge University Press)
{
	int j,iq,ip,i;
	float tresh,theta,tau,t,sm,s,h,g,c,*b,*z;

	b=vector(1,n);
	z=vector(1,n);
	for (ip=1;ip<=n;ip++) {								// Initialise to the identity matrix
		for(iq=1;iq<=n;iq++) v[ip][iq]=0.0;
		v[ip][ip]=1.0;
	}
	for (ip=1;ip<=n;ip++) {								// Initialise b and d to the diagonal
		b[ip]=d[ip]=a[ip][ip];							// of a
		z[ip]=0.0;										// This vector will accumulate terms
	}													//   of the form tapq as in equation 
	//*nrot=0;											//   (11.1.14)
	for(i=1;i<=50;i++) {
		sm=0.0;
		for (ip=1;ip<=n-1;ip++) {						// Sum off diagonal elements
			for(iq=ip+1;iq<=n;iq++)
				sm += fabs(a[ip][iq]);
		}
		if (sm < 1e-15)	{								// The normal return (originally 
			free_vector(z,1,n);							// sm ==0.0), modified so as not to 
			free_vector(b,1,n);							// rely on quadratic convergence to
			return;										// machine underflow.
		}
		if(i < 4)
			tresh=0.2*sm/(n*n);							// ...on the first three steps
		else
			tresh=0.0;									// ...thereafter
		for(ip=1;ip<=n-1;ip++) {
			for(iq=ip+1;iq<=n;iq++) {
				g=100.0*fabs(a[ip][iq]);
				// After four sweeps, skip the rotation if the off-diagonal element is too small.
				if (i > 4 && (float)(fabs(d[ip])+g) == (float)fabs(d[ip])
					&& (float)(fabs(d[iq])+g) == (float)fabs(d[iq]))
					a[ip][iq]=0.0;
				else if (fabs(a[ip][iq]) > tresh) {
					h=d[iq]-d[ip];
					if ((float)(fabs(h)+g) == (float)fabs(h))
						t=(a[ip][iq])/h;				// t = 1/(2theta)
					else {
						theta=0.5*h/(a[ip][iq]);		// Equation (11.1.10)
						t=1.0/(fabs(theta)+sqrt(1.0+theta*theta));
						if (theta < 0.0) t = -t;
					}
					c=1.0/sqrt(1+t*t);
					s=t*c;
					tau=s/(1.0+c);
					h=t*a[ip][iq];
					z[ip] -= h;
					z[iq] += h;
					d[ip] -= h;
					d[iq] += h;
					a[ip][iq]=0.0;
					for(j=1;j<=ip-1;j++) {				// Case of rotations 1 <= j < p
						ROTATE(a,j,ip,j,iq,tau,s);
					}
					for(j=ip+1;j<=iq-1;j++) {			// Case of rotations p < j < q
						ROTATE(a,ip,j,j,iq,tau,s);
					}
					for(j=iq+1;j<=n;j++) {				// Case of rotations q < j <= n
						ROTATE(a,ip,j,iq,j,tau,s);
					}
					for(j=1;j<=n;j++) {				
						ROTATE(v,j,ip,j,iq,tau,s);
					}
	//				++(*nrot);
				}
			}
		}
		for (ip=1;ip<=n;ip++) {
			b[ip] += z[ip];
			d[ip]=b[ip];								// Update d with the sum of tapq
			z[ip]=0.0;									// and reinitialize z;
		}
	}
	nrerror("Too many iterations in routine jacobi");
}

main(int argc, char* argv[])
{
	int i,j,k;
	const int N = 10;

	char* ifilename = "e:\\DeleteMe\\test_input.txt";
	char* rfilename = "e:\\DeleteMe\\test_output.txt";

	float** A;
	float** D;
	float** I;

	A = matrix(1,N,1,N);
	D = matrix(1,N,1,N);
	I = matrix(1,N,1,N);

	float W[N+1];		

	A[1][1] = 1.0;
	A[2][1] = 2.0;
	A[3][1] = 3.0;

	A[1][2] = 2.0;
	A[2][2] = 4.0;
	A[3][2] = 5.0;

	A[1][3] = 3.0;
	A[2][3] = 5.0;
	A[3][3] = 6.0;

	ifstream inputfile;
	inputfile.open(ifilename,ios::in|ios::nocreate);

	ofstream resfile;
	resfile.open(rfilename,ios::out|ios::trunc);
	
	unsigned int n_slices, n_cameras, n_leds;
	inputfile >> n_slices;
	inputfile >> n_cameras;
	inputfile >> n_leds;

	resfile << n_slices << " " << n_cameras << " " << n_leds << "\n\n";

	int flag;
	int counter = 0;
	long double mean[3];

	for(i=0;i<(n_slices*n_cameras*n_leds);i++)
	{	
		//load the flag
		inputfile >> flag;

		if(flag)
		{
			//load the data
			for(j = 1; j <= N; j++)		
			{
				for(k = 1; k <= N; k++)
				{
					inputfile >> A[j][k];
				}
			}
			for(j = 0; j < 3; j++)		{inputfile >> mean[j];}

			//copy the data
			for(j = 1; j <= N; j++)
			{
				for(k = 1; k <= N; k++)		
				{
					D[j][k] = I[j][k] = A[j][k];
					// D is a copy to stay
					// I is for input to jacobi(), then gets destroyed;
				}
			}



			//calculate the eigenvalues
			int* nrt; // number of rotations
			jacobi(I,N,W,A,nrt);

			if((counter % 10)==0) {cout << ++counter << " matrices processed.\n";}

			//save the results
			resfile << "1 ";
			for(j = 1; j <= N; j++)	{resfile << W[j] << " ";}	resfile << "\n";
			for(j = 1; j <= N; j++)
			{
				for(k = 1; k <= N; k++)		
				{
					if (fabs(A[j][k])<1e-15)		{resfile << 0 << " ";}
					else							{resfile << A[k][j] << " ";}
				}
			}
			resfile << "\n";
			//and the mean
			for(j = 0; j < 3; j++)		{resfile << mean[j] << " ";} 
			resfile << "\n";
			//and the original data
			for(j = 1; j <= N; j++)
			{
				for(k = 1; k <= N; k++)		
				{
					resfile << D[j][k] << " ";
				}
			}
			resfile << "\n";

		}
		else
		{
			resfile << "0 \n";
		}
	}

	free_matrix(A,1,N,1,N);
	free_matrix(D,1,N,1,N);
	free_matrix(I,1,N,1,N);

	inputfile.close();
	resfile.close();
}
