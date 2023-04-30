/* A Program Of Graphic Representation Of The Blood Circulation By #Insan_Technology_Company 
Eng. AbdAllah Islam Bin ElHassan
https://github.com/ai1islam1411/A-Program-Of-Graphic-Representation-Of-The-Blood-Circulation 
https://insantechnology.com */

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include<math.h>
#include<map.h>
#include<string.h>
#include<stack.h>
#include <time.h>
#include<iostream>
#include<iomanip>
#include <SFML/Graphics.hpp>
#define no_of_nodes 8
#define size 10
#define areaofVessels 1	 //1cm^3
#define redcellBody 100000
#define whitecellBody 5000
#define platletBody 25000
using namespace std;

void addOrgan(string organname);
int TraverseBody(string s1, int lifetime);

struct node{
	char name[15];
	int distance;
	int flowrate;
	int visited;
	struct node *next;
};

struct node organ[no_of_nodes];
int no_of_organs=0;

struct redcell{
	char organname[15];
	int cellcount;
	int visitedTime;
};
struct redcell redCellOrgan[no_of_nodes];

struct whitecell{
	char organname[15];
	int cellcount;
	int visitedTime;
};
struct whitecell whiteCellOrgan[no_of_nodes];

struct platelet{
	char organname[15];
	int cellcount;
	int visitedTime;
};
struct platelet plateletOrgan[no_of_nodes];

char arr[8][15] = {"leftAtrium","leftVentricle","RightAtrium","RightVentricle","lungs","brain","liver","kidney"};

void redcellTraverse(int noOfDay){
	int alltime, minPerDay =1140;
	cout<<"Red cells count in Body : "<<redcellBody<<"\n"<<endl;
	for(int i=0;i<no_of_nodes;i++){
		strcpy(redCellOrgan[i].organname,arr[i]);
		redCellOrgan[i].visitedTime=0;
	}
	
	string s1="Redcell";
	alltime=TraverseBody(s1,minPerDay); // 1140 min to 1 day
	alltime= alltime* noOfDay;
	cout<<"No of times visited."<<endl;
	cout<<"----------------------------\n"<<endl;
	
	for(int n=0;n<no_of_nodes;n++){
		redCellOrgan[n].visitedTime = redCellOrgan[n].visitedTime*noOfDay;
		cout<<"|"<<redCellOrgan[n].organname<<"-"<<redCellOrgan[n].visitedTime<<"|";
	}
	cout<<"\n\n\n probability of red cell traverse through the body and cell count. "<<endl;
	cout<<"-------------------------------------------------------------------------\n"<<endl;
	
	for(int i=0;i<8;i++){
		int count=redCellOrgan[i].visitedTime;
		float probability=((float)count/alltime)*100;
		int cellcount= redcellBody*(probability/100);
		redCellOrgan[i].cellcount=cellcount;
		cout<<"\t"<<left<<setw(20)<<redCellOrgan[i].organname <<" : " <<probability<<"%"<<right<<setw(25)<<setfill(' ')<<"cell count : "<<cellcount<<endl;
	}
	cout<<"\n\n";	
}

void whitecellTraverse(int noOfDay){
	int alltime,minPerDay=1140;
	cout<<"White cells count in Body : "<<whitecellBody<<"\n"<<endl;
	for(int i=0;i<no_of_nodes;i++){
		strcpy(whiteCellOrgan[i].organname,arr[i]);
		whiteCellOrgan[i].visitedTime=0;
	}
	string s1="whitecell";
	alltime=TraverseBody(s1,minPerDay); // 1140 min per 1 day
	alltime = alltime * noOfDay;
	cout<<"No of times visited"<<endl;
	cout<<"----------------------------\n"<<endl;
	
	for(int n=0;n<no_of_nodes;n++){
		whiteCellOrgan[n].visitedTime=whiteCellOrgan[n].visitedTime* noOfDay;
		cout<<"|"<<whiteCellOrgan[n].organname<<"-"<<whiteCellOrgan[n].visitedTime<<"|";
	}
	cout<<"\n\n\n probability of white cell traverse through the body and cell count. "<<endl;
	cout<<"-------------------------------------------------------------------------\n"<<endl;
	
	for(int i=0;i<8;i++){
		int count=whiteCellOrgan[i].visitedTime;
		float probability=((float)count/alltime)*100;
		int cellcount= whitecellBody*(probability/100);
		cout<<"\t"<<left<<setw(20)<<whiteCellOrgan[i].organname <<" : " <<probability<<"%"<<right<<setw(25)<<setfill(' ')<<"cell count : "<<cellcount<<endl;
	}
	cout<<"\n";
}

void plateletTraverse(int noOfDay){
	int alltime,minPerDay=1140;
	cout<<"platlets count in Body : "<<platletBody<<"\n"<<endl;
	for(int i=0;i<no_of_nodes;i++){
		strcpy(plateletOrgan[i].organname,arr[i]);
		plateletOrgan[i].visitedTime=0;
	}
	string s1="platelet";
	alltime=TraverseBody(s1,minPerDay); //1140 min per one day
	alltime=alltime *noOfDay;
	cout<<"No of times visited"<<endl;
	cout<<"----------------------------\n"<<endl;
	
	for(int n=0;n<no_of_nodes;n++){
		plateletOrgan[n].visitedTime=plateletOrgan[n].visitedTime*noOfDay;
		cout<<"|"<<plateletOrgan[n].organname<<"-"<<plateletOrgan[n].visitedTime<<"| ";
	}
	cout<<"\n\n\n probability of platlets cell traverse through the body and cell count. "<<endl;
	cout<<"------------------------------------------------------------------------------\n"<<endl;
	
	for(int i=0;i<8;i++){
		int count=plateletOrgan[i].visitedTime;
		float probability=((float)count/alltime)*100;
		int cellcount= platletBody*(probability/100);
		cout<<"\t"<<left<<setw(20)<<plateletOrgan[i].organname <<" : " <<probability<<"%"<<right<<setw(25)<<setfill(' ')<<"cell count : "<<cellcount<<endl;
	}
	cout<<"\n";
}

int TraverseBody(string s1, int lifetime){
	int M=0; 
	int no_of_time=0;
	int prev_Rand=0,RandIndex[250];
	srand ( time(0) );
	
	for(int i = 0; i<250; i++) { 
      RandIndex[i]=rand()%3+1;
   }
   cout<<"\n";
	
	while(lifetime>0){
		struct node *ptr=organ;
		struct node *qtr;
		struct node *last;
		for(int a=0;a<no_of_nodes;a++){
			organ[a].visited=0;
		}

		while(ptr->visited!=1){			
			ptr->visited=1;
			if(lifetime<=0){
				break;
			}
			last=ptr;
			if(last->next->next!=NULL){
				for(int j=0;j<RandIndex[M];j++){
					last=last->next;
				}
				M++;
				
			}
			else{
				last=ptr->next;
			}
			last->visited=1;
			int distance=last->distance;
			int flowrate=last->flowrate;
			int speed=flowrate/areaofVessels;
			int time=distance/speed;
			lifetime=lifetime-time;

			qtr=organ;
			char temp[15];
			strcpy(temp,last->name);
			while(strcmp(qtr->name,temp)){
				qtr++;	
			}
			ptr=qtr;
		}
		no_of_time++;
		
		if(s1=="Redcell"){
			for(int m=0;m<no_of_nodes;m++){
				if(organ[m].visited==1)	{
					redCellOrgan[m].visitedTime++;
				}
			}
		}
		else if(s1=="whitecell"){
			for(int m=0;m<no_of_nodes;m++){
				if(organ[m].visited==1)	{
					whiteCellOrgan[m].visitedTime++;
				}
			}
		}
		else if(s1=="platelet"){
			for(int m=0;m<no_of_nodes;m++){
				if(organ[m].visited==1)	{
					plateletOrgan[m].visitedTime++;
				}
			}
		}	
	
	}
	return no_of_time;
}

void addOrgan(char organname[]){
		strcpy(organ[no_of_organs].name,organname);
		organ[no_of_organs].distance=0;
		organ[no_of_organs].flowrate=0;
		organ[no_of_organs].next=NULL;
		no_of_organs++;
}

void addedgeVessels(char start[], char end[], int dist,int rate){
	struct node *ptr=organ;
	while(strcmp(ptr->name,start)){
		ptr++;
	}

	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *last=NULL;
	if(ptr->next==NULL){
		ptr->next=newnode;
		strcpy(newnode->name,end);
		newnode->distance=dist;
		newnode->flowrate=rate;
		newnode->next=NULL;
	}
	else{
		last=ptr;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=newnode;
		strcpy(newnode->name,end);
		newnode->distance=dist;
		newnode->flowrate=rate;
		newnode->next=NULL;
	}
}


void printBloodSystem(){
	struct node *ptr=organ;
	struct node *last=NULL;
	for(int i=0;i<no_of_nodes;i++){
	
		last=ptr;
		cout<<"Adjacent organ of "<<last->name<<"\n";
		while(last->next!=NULL){
			last=last->next;
			cout<<"\t"<<last->name<<"\t("<<" distance:"<<last->distance<<"cm "<<"flow rate: "<<last->flowrate<<"ml/min)"<<endl;
		}
		ptr++;
		cout<<"\n\n";
	}		
}

int main(){
	int choice;
	int lifetimeRedcell= 120;	
	int lifetimeWhitecell=20;	
	int lifetimePatlets=5;
	
	char organ1[15]="leftAtrium"; 	addOrgan(organ1);
	char organ2[15]="leftVentricle"; addOrgan(organ2);
	char organ3[15]="RightAtrium";    addOrgan(organ3);
	char organ4[15]="RightVentricle"; addOrgan(organ4);
	char organ5[15]="lungs"; 			addOrgan(organ5);
	char organ6[15]="brain"; 			addOrgan(organ6);
	char organ7[15]="liver"; 			addOrgan(organ7);
	char organ8[15]="kidney"; 		addOrgan(organ8);
	
	addedgeVessels(organ1,organ2,10,10);
	addedgeVessels(organ2,organ6,200,50);
	addedgeVessels(organ2,organ7,150,50);
	addedgeVessels(organ2,organ8,100,100);
	addedgeVessels(organ6,organ3,200,50);
	addedgeVessels(organ7,organ3,150,50);
	addedgeVessels(organ8,organ3,100,100);
	addedgeVessels(organ3,organ4,10,10);
	addedgeVessels(organ4,organ5,50,50);
	addedgeVessels(organ5,organ1,50,50);
	
	cout<<"************* INSAN BLOOD CIRCULATORY SYSTEM ***************\n"<<endl;
	printBloodSystem();
	cout<<"************** INSAN RED CELLS TRAVERSE THROUGH BODY IN THEIR LIFE TIME. **************************\n"<<endl;
	redcellTraverse(lifetimeRedcell);
	cout<<"\n************ INSAN WHITE CELLS TRAVERSE THROUGH BODY IN THEIR LIFE TIME. *******************\n"<<endl;
	whitecellTraverse(lifetimeWhitecell);
	cout<<"\n************ INSAN PLATELETS TRAVERSE THROUGH BODY IN THEIR LIFE TIME. *************************\n"<<endl;
	plateletTraverse(lifetimePatlets);
	
	while(1){
	cout<<"------------------------------------------------------------------------------\n"<<endl;
	cout<<"1. Insan Red Cell Traverse Through Body...."<<endl;
	cout<<"2. Insan White Cell Traverse Through Body...."<<endl;
	cout<<"3. Insan Platelets Traverse Through Body...."<<endl;
	cout<<"4. Exit Insan\n"<<endl;
	
	cout<<"Enter Your Choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			int n;
			cout<<"Enter How Many Days To Traverse The Red Cells (Below 120) (Days):";
			cin>>n;
			if(n>lifetimeRedcell)
				cout<<"Enter Below 120 Days. Life Time Of Red Cell : 120 Days"<<endl;	
			else
				redcellTraverse(n);
			break;	
		case 2:
			int l;
			cout<<"Enter How Many Days To Traverse The White Cells (Bellow 20) (Days): ";
			cin>>l;
			if(l>lifetimeWhitecell)
				cout<<"Enter Below 20 Days. Life Time Of White Cell : 20 Days"<<endl;
			else
				whitecellTraverse(l);
			break;				
		case 3:
			int m;
			cout<<"Enter Time To Traverse The Platelets (Below 5) (Days): ";
			cin>>m;
			if(m>lifetimePatlets)
				cout<<"Enter Below 5 Days. Life Time Of Platelets : 5 Days"<<endl;
			else
				plateletTraverse(m);
			break;	
		case 4:
			cout<<"Thank you Dear Insan";
			return 0;
		default:
			cout<<"Enter Valid Choice";
			break;
	}
	}
}
