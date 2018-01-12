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
    int cnt1=0, cnt2=0;



    while(!f1.eof())
    {
      getline(f1,l,',');
      if(n%2==0)
        arr1[cnt1++]=l;
      else
        arr2[cnt2++]=l;

      n++;
    }

    for(int i=0;i<cnt1;i+=2)
    {
        cout<<arr1[i]<<" "<<endl;
    }




    for(int i=0;i<cnt2;i++)
    {
        cout<<arr2[i]<<" ";
    }

    cout<<endl;
    no_fields=n/2;
  //  cout<<no_fields;
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

/*

    int val;

    do
    {

        cout<<"Enter: \n1 to print file data\n2 to find sum of a given field entries\n0 to exit: ";
        cin>>val;

        char *str;
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
            cin>>str;
            if(strcmp("String",str)==0)
            {
                cout<<"This field is not of numeric type\n";
            }


            else if(strcmp("Float",str)==0)
            {
                float sum=0.0;
                int i;
                for(i=0;i<no_records;i++)
                {
                    sum+=data[i].getFloat();
                }
                cout<<"Sum is = "<<sum<<endl;
            }

            else if(strcmp("Int",str)==0)
            {
                int sum=0;
                int i;
                for(i=0;i<no_records;i++)
                {
                    sum+=data[i].getInt();
                }

                cout<<"Sum is = "<<sum<<endl;
            }

            else
            {
                cout<<"This field does not exist\n";
            }

        }

    }while(val!=0);
*/

	return 0;
}

