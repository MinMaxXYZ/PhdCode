#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <math.h>

#define TRUE	1
#define FALSE	0

#define MAX_N_RIDGEPOINTS	350
#define N_ARGC				3

float a[MAX_N_RIDGEPOINTS][3];
float b[MAX_N_RIDGEPOINTS][3];

unsigned int sizea, sizeb;
unsigned int i,j;

float xa,ya,za, xb,yb,zb, x,y,z;

long double EucDist(	long double x1,long double y1,long double z1,
						long double x2,long double y2,long double z2)
{
	long double dx = x1-x2;
	long double dy = y1-y2;
	long double dz = z1-z2;
	long double d = sqrt((dx*dx)+(dy*dy)+(dz*dz));
	return(d);
}

void main(int argc, char *argv[])
{
	//read arguments and determine slice distance and thickness, and the landmark heights
	char* fileaname = argv[1];
	char* filebname = argv[2];


	// data reality checks
	unsigned short int data_valid = TRUE;

	if ( argc > N_ARGC )
	{
		data_valid = FALSE;
		printf("Too many arguments. Cannot process.\n");
		exit(0);
	}

	if ( argc < N_ARGC )
	{
		data_valid = FALSE;
		printf("Too few arguments. Cannot process.\n");
		exit(0);
	}


	//load the start file size (after the fourth semicolon)
	ifstream filea;
	filea.open(fileaname,ios::in);
	filea >> sizea;

	//load the end file size
	ifstream fileb;
	fileb.open(filebname,ios::in);
	fileb >> sizeb;

	//check that both the files are valid
	if( (!filea) || (!fileb))
	{
		data_valid = FALSE;
		printf("At least one of the two input files is invalid. Cannot process.\n");
		filea.close();
		fileb.close();
		exit(0);
	}


	//too many vertices
	if( (sizea>MAX_N_RIDGEPOINTS) || (sizeb>MAX_N_RIDGEPOINTS) )
	{
		data_valid = FALSE;
		printf("Input files contain too many vertices. Cannot process.\n");
		filea.close();
		fileb.close();
		exit(0);
	}


	// processing
	if(data_valid)
	{
		// load the files onto arrays


		// first file
		for(i = 0; i < sizea; i++)
		{
			filea >> x;		a[i][0] = x;
			filea >> y;		a[i][1] = y;
			filea >> z;		a[i][2] = z;
		}
		
		// second file
		for(i = 0; i < sizeb; i++)
		{
			fileb >> x;		b[i][0] = x;
			fileb >> y;		b[i][1] = y;
			fileb >> z;		b[i][2] = z;
		}
		
		fflush(NULL);
		filea.close();
		fileb.close();

		// calculate the distance
		long double mindist;
		long double currdist;

		long double totaldist1 = 0.0;
		for(i = 0; i < sizea; i++)
		{
			xa = a[i][0];	ya = a[i][1];	za = a[i][2];	
			mindist = 999999.0;
			for(j = 0; j < sizeb; j++)
			{
				xb = b[j][0];	yb = b[j][1];	zb = b[j][2];	
				currdist = EucDist(xa,ya,za,	xb,yb,zb);
				if (currdist < mindist) {mindist = currdist;}
			}
			totaldist1 += mindist;
		}

		long double totaldist2 = 0.0;
		for(j = 0; j < sizeb; j++)
		{
			xb = b[j][0];	yb = b[j][1];	zb = b[j][2];	
			mindist = 999999.0;
			for(i = 0; i < sizea; i++)
			{
				xa = a[i][0];	ya = a[i][1];	za = a[i][2];	
				currdist = EucDist(xa,ya,za,	xb,yb,zb);
				if (currdist < mindist) {mindist = currdist;}
			}
			totaldist2 += mindist;
		}
		cout << "Summed minimum inter-curve distance between A and B is " << (totaldist1 + totaldist2) << "\n";

	}//data valid
	
}