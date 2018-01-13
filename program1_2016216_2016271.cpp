#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;


class obj
{
private:

    int Int;
    float Float;
    string String;

public:

    obj()
    {
        Int=0;
        Float=0.0;
        String="";

    }

    obj(int i, float f, string s)
    {
        Int=i;
        Float=f;
        String=s;
    }

    void getdata()
    {
        cout<<Int<<"\t";
        cout<<Float<<"\t";
        cout<<String<<endl;
    }

    float getFloat()
    {
        return Float;
    }

    int getInt()
    {
        return Int;
    }

};

int main()
{
    int start_s=clock();
    int no_records=3;
    int no_fields=3;

    obj data[no_records];

    int size1=2;
    int size2=4;
    int size3=20;

    ifstream f1;
    f1.open("data.txt");

    int n=0;
    int a;
    float b;
    string c;
    char l[20];
    int x=0;
    while(!f1.eof())
    {
      f1>>l;

      if(n%no_fields==0)
      {
          a=atoi(l);

      }

      else if(n%no_fields==1)
      {

          b=atof(l);

      }

      else
      {
            c=(char*)l;
            obj obj1(a,b,c);
            data[x]=obj1;
      //      data[x].getdata();
            x++;
      }
      n++;
    }



    f1.close();


    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;


    /*
    //make the user file
    1) (wont meta )use data files
    2) meta,data files*/





    int val;

    do
    {

        cout<<"Enter: \n1 to print file data\n2 to find sum of a given field entries\n0 to exit: ";
        cin>>val;

        char *str;
        if(val==1)
        {
            int i=0;
            cout<<"Int\tFloat\tString"<<endl;
            for(i=0;i<no_records;i++)
            {
                data[i].getdata();
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


	return 0;
}
