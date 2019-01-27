// Lawrence Scroggs  CS163 Program 1
// This program will build a list of jobs
// It will use linear linked lists to build a list of job locations
// then an additional LLL to build the job info.  This is the first 
// attempt at using ADTs and will use these to keep all the data and 
// memory private from the user and client

#include "job.h"
using namespace std;


int main()
{
  list locations;
  bool temp = true;
  int displayCatch = 0;


  locations.intro();
  do
  {
    locations.buildLocation();
    temp = locations.goAgain();

  }while(temp == true);
  temp = false;

  cout << "Would you like to display the Locations? ";
  temp = locations.yesNo();
  
  if(temp == true)
    locations.display();

  while(displayCatch != 1)
  {
    displayCatch = locations.displayLocationJobs();

  }  





  return 0;
}

