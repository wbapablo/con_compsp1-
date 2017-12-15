#include <time.h>
#include <stdio.h>
#include <vector>
#include <math.h>

#include <iostream>
#include <fstream>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void fill_connection_mat2(
		Mat						    ad_mat,
		vector<vector<int>>& 		conexiones,
		vector<vector<int>>& 		tails,
		const int* 					klabels,
		int 						sz,
		int& 						group_i,
	    vector<double> kr,
	    vector<double> kg,
	    vector<double> kb,
		vector<double>&				avg_r,
		vector<double>&				avg_g,
		vector<double>&				avg_b
		)
{

	group_i=0;

	double d_r, d_g, d_b;
	double color_d;
	double th=20;
	

	int x,y;

	int run;

	double a_r=0,a_g=0,a_b=0,colcont=0;
	int prom;
	bool t_flag = false;

	//Check ALL super-pixels
	for(int ic=0; ic < sz; ic++){
		if(conexiones[ic][1]==0){
			conexiones[ic][1]=1;
			conexiones[ic][2]=group_i;

			//Each temp will contain all the group members
			//If the above condition was satisfied, means that we are dealing with a new 'father' of the group
			vector<int> temp(0);
			temp.push_back(conexiones[ic][0]);

			// kr,g,b contain the super-pixel colours
			a_r=kr[conexiones[ic][0]];
			a_g=kg[conexiones[ic][0]];
			a_b=kb[conexiones[ic][0]];

			colcont++;


			for(int ic2=0; ic2 < temp.size() ; ic2++){

				//En 'y' estoy tomando el último elemento del temp que en cada ciclo es el padre y de él me anclo para analizar a los hijos
				y=temp[ic2];
				run=sz-y;
				
				for(int ic3=1; ic3<20;ic3++){
					
					//x=y+ic3;
					x=ic3;
						// Checar si es adyacente y si no está visitado ya
				    
					if((ad_mat.at<double>(y,x)==1)&&(conexiones[x][1]==0)){

						d_r=abs(kr[y]-kr[x]);
						d_g=abs(kg[y]-kg[x]);
						d_b=abs(kb[y]-kb[x]);

						color_d=sqrt(pow(d_r,2) + pow(d_g,2) + pow(d_b,2));

						if (color_d<th){
							/*
							if(conexiones[x][1]>0){

								conexiones[y][2]=conexiones[x][2];
								tails[conexiones[y][2]].push_back(conexiones[y][0]);
								t_flag = true;
								continue;
							}*/


							
							temp.push_back(x);
							
							a_r += kr[x];
							a_g += kg[x];
							a_b += kb[x];

							colcont++;

							conexiones[x][1]=1;
							conexiones[x][2]=group_i;
						}
					}
				}
			}
			
			if(!t_flag){
				group_i++;
				tails.push_back(temp);
				t_flag=false;
			}
			
			
			prom=a_r/colcont;
			avg_r.push_back(prom);
			prom=a_g/colcont;
			avg_g.push_back(prom);
			prom=a_b/colcont;
			avg_b.push_back(prom);
			colcont=0,a_r=0,a_g=0,a_b=0;

		}
	}



}

int main(void){
//Variables definition
	Mat						    m_ad;
	vector<vector<int>> 		conexiones;
	vector<vector<int>> 		tails;
	const int* 					klabels;
	int 						sz=20;
	int 						group_i;
    vector<double> 				kr;
    vector<double>				kg;
    vector<double> 				kb;
	vector<double>				avg_r;
	vector<double>				avg_g;
	vector<double>				avg_b;


	m_ad = cv::Mat(sz,sz, CV_64FC1,cvScalar(0));

	vector <int> temp(0);

	for (int i=0; i < sz ; i++){

		for(int j=0; j < 3 ; j++){
			temp.push_back(0);
		}
		conexiones.push_back(temp);
		temp.clear();
		conexiones[i][0]=i;

	}




    char sep = ',';
    string value;

  	int i_dec;
  	std::string::size_type siz; 

    fstream myfiler;
    myfiler.open ("../rr.csv");
    for(int i=0; i<4; i++)
    {
    	for(int j=0; j<5; j++){
    		getline(myfiler,value,sep);
    		i_dec = std::stoi (value,&siz);
			kr.push_back(i_dec);
			cout << kr.back() << " " ;

    	}
    	cout << endl;
    }
    myfiler.close();
    cout << endl;

    fstream myfileg;
    myfileg.open ("../gg.csv");
    for(int i=0; i<4; i++)
    {
    	for(int j=0; j<5; j++){
    		getline(myfileg,value,sep);
    		i_dec = std::stoi (value,&siz);
			kg.push_back(i_dec);
			cout << kg.back() << " " ;
    	}
    	cout << endl;
    }
    myfileg.close();
    cout << endl;

   	fstream myfileb;
    myfileb.open ("../bb.csv");
    for(int i=0; i<4; i++)
    {
    	for(int j=0; j<5; j++){
    		getline(myfileb,value,sep);
    		i_dec = std::stoi (value,&siz);
			kb.push_back(i_dec);
			cout << kb.back() << " " ;
    	}
    	cout << endl;
    }
    myfileb.close();

    fstream matad;
    matad.open("../mat_de_adj.csv");
    for(int i=0; i<20; i++){
    	for(int j=0; j<20; j++){
    		getline(matad,value,sep);
    		i_dec = std::stoi (value,&siz);
			m_ad.at<double>(i,j)=(double)i_dec;
			cout << m_ad.at<double>(i,j) << " " ;
    	}
    	cout << endl;
    }
    matad.close();
    cout << endl;
    cout << endl;

   	fill_connection_mat2(m_ad,conexiones,tails,klabels,sz,group_i, kr, kg, kb,avg_r,avg_g,avg_b);
   	cout << "RES: "<<endl;
   	for(int i=0; i<tails.size();i++){
   		cout << "grupo: " << i<<" -> ";
   		for (int j = 0; j < tails[i].size(); j++)
   		{
   			/* code */
   			cout << " " << tails[i][j];
   		}
   		cout << endl;
   	}

   	
	for (int i=0; i < sz ; i++){

		cout<< conexiones[i][0] <<" " << conexiones[i][1] <<" "<<conexiones[i][2] <<endl;

	}



}