#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


int main()
{
    int no_records;
    int no_fields;

    int size1;
    int size2;
    int size3;

    ifstream f1;

    f1.open("metadata.txt");

    int n=0;
    int a;
    float b;
    string c;
    string l;
    int x=0;

    string arr1[100000];
    string arr2[100000];
    string arr3[100000];
    int cnt1=0, cnt2=0,cnt3=0;



    while(!f1.eof())
    {
      f1>>l;

      if(n%3==0)
        arr1[cnt1++]=l;
      else if(n%3==1)
        arr2[cnt2++]=l;
      else
        arr3[cnt3++]=l;

      n++;
    }

    no_fields=n/3;

    f1.close();

    ifstream f2;

    f2.open("data.txt");

    n=0;

    string temp;
    while(!f2.eof())
    {
      getline(f2,temp);
      n++;
    }

 //   cout<<n<<endl;

    f2.close();

    string datasaver[n+1][no_fields+1];

    ifstream f3;
    string data;
    f3.open("data.txt");

    string p;
    int q=0, r=0;

   // cout<<"HEEEEEEEEEEE";
    while(!f3.eof())
    {
        f3>>p;
       // cout<<p;
        datasaver[q][r]=p;
        r++;
        //cout<<r;
        if(r%no_fields==0)
            {
                q++;
                r=0;
            }
       // cout<<"inf";
    }

   // cout<<"SUPPPPPP";


    f3.close();



    int val;

    do
    {

        cout<<"Enter: \n1 to print file data\n2 to find sum of a given field entries\n0 to exit: ";
        cin>>val;

        char str[1024];
        if(val==1)
        {
             for(int i=0; i<n; i++)
             {
                for(int j=0; j<no_fields; j++)
                {
                    cout<<datasaver[i][j]<<" ";
                }

                cout<<endl;
            }

        }

        else if(val==2)
        {
            cout<<"Enter the field name whose sum over all records need to be calculated: ";
            char sp[10];
            gets(sp);
            gets(str);
            string temp;
            int k=0;
            int flag=0;
            for(int i=0;i<cnt1;i++)
            {
                const char *comp = arr1[i].c_str();
                if(strcmp(str,comp)==0)
                {
                    k=i;
                    temp=arr2[i];
                    flag=1;
                    break;
                }


            }

            if(flag==0)
                cout<<"No such field"<<endl;
            else
            {
                const char* comp2 = temp.c_str();
                if(strcmp(comp2,"int")==0)
                {
                    int sum=0;
                    for(int j=0;j<n;j++)
                    {
                        const char* addi = (datasaver[j][k]).c_str();
                        sum+=atoi(addi);
                    }

                    cout<<"The sum is: "<<sum<<endl;
                }

                else if(strcmp(comp2,"float")==0)
                {
                    float sum=0;
                    for(int j=0;j<n;j++)
                    {
                        const char* addi = (datasaver[j][k]).c_str();
                        sum+=atof(addi);
                    }

                    cout<<"The sum is: "<<sum<<endl;


                }

                else if(strcmp(comp2,"double")==0)
                {
                    double sum=0;

                    for(int j=0;j<n;j++)
                    {
                        const char* addi = (datasaver[j][k]).c_str();
                        sum+=atof(addi);
                    }

                    cout<<"The sum is: "<<sum<<endl;
                }

                else
                {
                        cout<<"Not a numeric field";
                }
            }


        }

    }while(val!=0);


	return 0;
}

