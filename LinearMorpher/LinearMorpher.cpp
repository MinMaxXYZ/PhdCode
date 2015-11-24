#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

#define MAX_N_SLICES		100
#define MAX_SLICE_SIZE		100
#define N_ARGC				6
#define MAX_STRLEN			500

float a_start[MAX_N_SLICES][MAX_SLICE_SIZE][3];
float a_end[MAX_N_SLICES][MAX_SLICE_SIZE][3];

unsigned int i;
int junk;

ofstream resfile;
const char* slash = "\\";
const char* didgit = "0";
const char* xtn = ".hci";

float wa,wb, xa,ya,za, xb,yb,zb, x,y,z;

void main(int argc, char *argv[])
{
	//read arguments and determine slice distance and thickness, and the landmark heights
	char* startfilename = argv[1];
	char* endfilename = argv[2];
	int n_steps = (int)atoi(argv[3]);
	char* outputpath = argv[4];
	char* prefix = argv[5];


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

	if ( n_steps < 3 )
	{
		data_valid = FALSE;
		printf("Too few steps requested (must be at least 3). No point in processing.\n");
		exit(0);
	}

	//load the start file size
	ifstream startfile;
	startfile.open(startfilename,ios::in/*|ios::nocreate*/);

	//load the end file size
	ifstream endfile;
	endfile.open(endfilename,ios::in/*|ios::nocreate*/);

	//check that both the files are valid
	if( (!startfile) || (!endfile))
	{
		data_valid = FALSE;
		printf("At least one of the two input files is invalid. Cannot process.\n");
		startfile.close();
		endfile.close();
		exit(0);
	}

	//check that files are of the same and right size and type
	unsigned int startcameras, startleds, startslices, starttones, startchannels;
	unsigned int endcameras, endleds, endslices, endtones, endchannels;

	startfile >> startcameras;	endfile >> endcameras;
	startfile >> startleds;		endfile >> endleds;
	startfile >> startslices;	endfile >> endslices;
	startfile >> starttones;	endfile >> endtones;
	startfile >> startchannels;	endfile >> endchannels;

	//not canonical
	if( (startcameras!=1) || (endcameras!=1))
	{
		data_valid = FALSE;
		printf("At least one of the two input files is not a canonical/full form. Cannot process.\n");
		startfile.close();
		endfile.close();
		exit(0);
	}

	//not same sizes
	if( (startleds!=endleds) || (startslices!=endslices) )
	{
		data_valid = FALSE;
		printf("Input files contain different number/arrangement of vertices. Cannot process.\n");
		startfile.close();
		endfile.close();
		exit(0);
	}

	//too many vertices
	if( (startslices>MAX_N_SLICES) || ((startcameras*endcameras)>MAX_SLICE_SIZE) )
	{
		data_valid = FALSE;
		printf("Input files contain too many vertices. Cannot process.\n");
		startfile.close();
		endfile.close();
		exit(0);
	}


	// processing
	if(data_valid)
	{
		//load the input files onto arrays
		for(unsigned int row = 0; row < startslices; row++)
		{
			for(unsigned int col = 0; col < (startcameras*startleds); col++)
			{
				fflush(NULL);

				//load next input file vertex
				startfile >> a_start[row][col][0];
				startfile >> a_start[row][col][1];
				startfile >> a_start[row][col][2];

				//load next output file vertex
				endfile >> a_end[row][col][0];
				endfile >> a_end[row][col][1];
				endfile >> a_end[row][col][2];

				//skip colour information
				for(i = 0; i < startchannels; i++)		{startfile >> junk;}
				for(i = 0; i < endchannels; i++)		{endfile >> junk;}

			}
		}
		fflush(NULL);
		startfile.close();
		endfile.close();

		//carry out the interpolation
		printf("Processing");
		for(int s = 0; s < n_steps; s++)
		{
			printf(".");

			// calculate the weights
			wb = ((float)s)/(((float)n_steps) - 1.0);
			wa = 1.0 - wb;

			//create the new file
			char resfilename[500];
			strcpy(resfilename,outputpath);
			char filenum[3];				_itoa(s,filenum,10);

			strcat(resfilename,slash);
			strcat(resfilename,prefix);
			if(s<10) {strcat(resfilename,didgit);}
			strcat(resfilename,filenum);
			strcat(resfilename,xtn);

			resfile.open(resfilename,ios::out|ios::trunc);

			//write the header of the new file
			resfile << "1\n" << startleds << " " << startslices << "\n255 1\n";
			
			//loop through the points
			for(unsigned int row = 0; row < startslices; row++)
			{
				for(unsigned int col = 0; col < (startcameras*startleds); col++)
				{

					// read the start point
					xa = a_start[row][col][0];
					ya = a_start[row][col][1];
					za = a_start[row][col][2];

					// read the end point
					xb = a_end[row][col][0];
					yb = a_end[row][col][1];
					zb = a_end[row][col][2];


					// calculate the interpolated point
					x = wa*xa + wb*xb;
					y = wa*ya + wb*yb;
					z = wa*za + wb*zb;

					// write the points out to the file
					resfile << x << " ";
					resfile << y << " ";
					resfile << z << " 200\n";
				}
			}

			//close

			resfile.close();
		}
	}
	
}