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

void cfc(
		int							y,
		int							x,
		Mat&					    ad_mat,
		vector<vector<int>>& 		conexiones,
		vector<int>&		 		temp,
		int 						sz,
		int							group_i,
	    vector<double>& kr,
	    vector<double>& kg,
	    vector<double>& kb,
		vector<double>&				avg_r,
		vector<double>&				avg_g,
		vector<double>&				avg_b,
		vector<vector<int>>& 		tails,
		bool& t_flag);

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
	

	int x=0,y=0;

	double a_r=0,a_g=0,a_b=0,colcont=0;
	int prom;
	bool t_flag = false;

	vector<int> temp(0);

	for (int i = 0; i < sz; i++)
	{
		
		if(conexiones[i][1]==0){
			temp.push_back(i);
			conexiones[i][1]=1;
			conexiones[i][2]=group_i;

			a_r=kr[conexiones[i][0]];
			a_g=kg[conexiones[i][0]];
			a_b=kb[conexiones[i][0]];

			colcont++;

			cfc(i,i,ad_mat,conexiones,temp,sz-i,group_i,kr,kg,kb,avg_r,avg_g,avg_b,tails,t_flag);
			if(!t_flag){
				group_i++;
				tails.push_back(temp);
				t_flag=false;

				prom = a_r/colcont;
				avg_r.push_back(prom);
				prom = a_g/colcont;
				avg_g.push_back(prom);
				prom = a_b/colcont;
				avg_b.push_back(prom);
				colcont=0,a_r=0,a_g=0,a_b=0;

			}{
				t_flag = false;
				colcont=0,a_r=0,a_g=0,a_b=0;
			}
			
			temp.clear();


		}
	}
}



void cfc(
		int							y,
		int							x,
		Mat&					    ad_mat,
		vector<vector<int>>& 		conexiones,
		vector<int>&		 		temp,
		int 						sz,
		int							group_i,
	    vector<double>& kr,
	    vector<double>& kg,
	    vector<double>& kb,
		vector<double>&				avg_r,
		vector<double>&				avg_g,
		vector<double>&				avg_b,
		vector<vector<int>>& 		tails,
		bool& t_flag
		){

	double d_r,d_g,d_b,color_d,colcont=0;
	double a_r=0,a_g=0,a_b=0;

	double th=20;
	
	for(int i=1; i<sz; i++){
		d_r=abs(kr[y]-kr[x+i]);
		d_g=abs(kg[y]-kg[x+i]);
		d_b=abs(kb[y]-kb[x+i]);

		color_d=sqrt(pow(d_r,2) + pow(d_g,2) + pow(d_b,2));

		if((ad_mat.at<double>(y,x+i)==1)&&(color_d<th)){

			if(conexiones[x+i][1]==0){
				conexiones[x+i][1]=1;
				temp.push_back(x+i);
				conexiones[x+i][2]=group_i;
				a_r += kr[x+i];
				a_g += kg[x+i];
				a_b += kb[x+i];
				colcont++;		

				cfc(x+i,x+i,ad_mat,conexiones,temp,(sz-i),group_i,kr,kg,kb,avg_r,avg_g,avg_b,tails,t_flag);

			}else if(conexiones[y][2]!=conexiones[x+i][2]){

				for(int t_i=0; t_i< temp.size(); t_i++){
					conexiones[temp[t_i]][2]=conexiones[x+i][2];
				}

				tails[conexiones[x+i][2]].insert(tails[conexiones[x+i][2]].end(),temp.begin(),temp.end());
				temp.clear();
				t_flag = true;

				a_r += kr[y];
				a_g += kg[y];
				a_b += kb[y];
				colcont++;	

			}
		}
	}
}

int main(void){
//Variables definition
	Mat						    m_ad;
	vector<vector<int>> 		conexiones;
	vector<vector<int>> 		tails;
	const int* 					klabels;
	int 						sz=25;
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
		conexiones[i][2]=-1;

	}




    char sep = ',';
    string value;

  	int i_dec;
  	std::string::size_type siz; 

    fstream myfiler;
    myfiler.open ("../rr.csv");
    for(int i=0; i<5; i++)
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
    for(int i=0; i<5; i++)
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
    for(int i=0; i<5; i++)
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
    for(int i=0; i<sz; i++){
    	for(int j=0; j<sz; j++){
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

	cout<<endl<<endl<< " R "<< " G " << " B " << endl;

	for (int i=0; i < avg_r.size() ; i++){

	cout<< avg_r[i] <<" " << avg_g[i] <<" "<<avg_b[i] <<endl;

	}



}