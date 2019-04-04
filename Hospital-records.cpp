#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class patient {
	char name[50];
	char doctorname[50];
	char adate[50];
	char dname[50];
	char age[50];
	char t[10];
	char gen[10];

	public:
	patient() { }

	void getdata() {
		cout<<endl<<"Enter name of patient = ";
		cin>>name;
	
		cout<<endl<<"Enter the age of patient = ";
		cin>>age;
		
		cout<<endl<<"Enter gender = ";
		cin>>gen;
		
		cout<<endl<<"Enter name of doctor = ";
		cin>>doctorname;
		
		cout<<endl<<"Enter date of admission = ";
		cin>>adate;
		
		cout<<endl<<"Enter the disease = ";
		cin>>dname;
		
		cout<<endl<<"Enter duration of treatment = ";
		cin>>t;
	}

	bool getinfo() {
		if(name[0] == '\0') {
  			return false;
		} else {
  			return true;
		}
	}

	int checkname(char a[50]) {
  		if(strcmp(a,name) == 0) {
    	    return 1;
  		} else {
    		return 0;
  		}
	}

	void setdata() {
		cout<<endl<<endl<<"Name of patient = "<<name;
		
		cout<<endl<<"Age = "<<age;
		
		cout<<endl<<"Gender = "<<gen;
		
		cout<<endl<<"Treatment is done by = "<<doctorname;
		
		cout<<endl<<"Admission date = "<<adate;
		
		cout<<endl<<"Diagnosed disease = "<<dname;
		
		
		cout<<endl<<"Treatment duration = "<<t;
	}
};

class doctor {
	char dname[50];
	char did[50];
	char dept[50];
	char age[50];
	char gen[10];
	
	public:
	doctor() { }
	void getdata() {
		cout<<endl<<"Enter name of Doctor = ";
		cin>>dname;
		
		cout<<endl<<"Enter ID of Doctor = ";
		cin>>did;
		
		cout<<endl<<"Enter department = ";
		cin>>dept;
		
		cout<<endl<<"Enter the age of Doctor = ";
		cin>>age;
		
		cout<<endl<<"Enter gender = ";
		cin>>gen;
	}
	
	bool getinfo() {
		if(dname[0] == '\0') {
  			return false;
		} else  {
  			return true;
		}
	}

	int checkname(char a[50]){
  		if(strcmp(a,dname) == 0) {
    		return 1;
  		} else {
    		return 0;
  		}	
	}


	void setdata() {
		cout<<endl<<"Name of Doctor = Dr."<<dname;
		
		cout<<endl<<"ID = "<<did;
		
		cout<<endl<<"Working Department = "<<dept;
		
		cout<<endl<<"Age = "<<age;
		
		cout<<endl<<"Gender = "<<gen;	
	}
};

main() {
	  char sname[50];
	  char sdname[50];
	  int a=99;
	  int h=0;
	  ofstream f;
	  ifstream g;
 
  	while(a!=0) { 
		cout<<endl;  
		cout<<endl<<"Enter which operation you want to perform"<<endl;
		cout<<"1-Enter new patient entry"<<endl;
		cout<<"2-Search a patient"<<endl;
		cout<<"3-List all information of all patients"<<endl;
		cout<<"4-Enter new doctor entry"<<endl;
		cout<<"5-Search a Doctor"<<endl;
		cout<<"6-List all information of all doctors"<<endl;
		cout<<"0-To exit"<<endl;

  		cin>>a;    
  		switch (a) {
	    	case 1:
	            f.open("pd.txt",ios::app|ios::binary);
	            patient *p ;
	            p = new patient();
	                          
	            cout<<"Enter the patients details";
	            p->getdata();
	            f.write((char *)p, sizeof(patient));
	            f.close();
	    	break;
	
	    	case 2:
	         	cout<<"Enter patient name you want to search :-";
	         	cin>>sname;
	         	h=0;
	         	g.open("pd.txt",ios::binary);
	         	g.seekg(0);
	         	while (g) {          
	              	patient *p2 ;
	              	p2 = new patient();
	              
	         		g.read((char *)p2, sizeof(patient));
	         
	         		if(p2->checkname(sname)==1){
	           			h=1;
	           			p2->setdata();
	         		}
	        	}
	        	g.close();
	        	if(h==0)
	          		cout<<"No data found with the given name";
	   		break;
	  		
			case 3:
	  			g.open("pd.txt",ios::binary);
	        	g.seekg (0, ios::beg);
			  	while (g) { 
	            	patient *p1 ;
	              	p1 = new patient();
	            	g.read((char *)p1, sizeof(patient));
	            
	            	if(p1->getinfo())
	                	p1->setdata();
	          	}
	          	g.close();
	  		break;
	
	    	case 4:
	            f.open("dd.txt",ios::app|ios::binary);
	            doctor *d ;
	            d = new doctor();              
	            cout<<"Enter the Doctor details";
	            d->getdata();
	            f.write((char *)d, sizeof(doctor));
	            f.close();
	    	break;
	
	    	case 5:
	         	cout<<"Enter Doctor name you want to search :-";
	         	cin>>sdname;
	         	h=0;
	         	g.open("dd.txt",ios::binary);
	         	g.seekg(0);
	         	while (g) {
	          		doctor *d2 ;
	              	d2 = new doctor();    
	         		g.read((char *)d2, sizeof(doctor));
	         		if(d2->checkname(sdname)==1) {
	           			h=1;
	           			d2->setdata();
	         		}
	        	}
	        	g.close();
	        	if(h==0)
	          		cout<<"No data found with the given name";
	   		break;
	   		
	  		case 6:	
	          	g.open("dd.txt",ios::binary);
			  	g.seekg (0, ios::beg);
			  	while (g){ 
	                doctor *d1 ;
	              	d1 = new doctor();
	              	g.read((char *)d1, sizeof(doctor));
	            
	            	if(d1->getinfo())
	                d1->setdata();
	          	}
	          	g.close();
	  		break;
	  		
			case 0:
	      		cout<<"Thank you for using";      
			break;
	
	  		default:
	      		cout<<"Please enter a valid option";
	  		break;
		}
	}
}
