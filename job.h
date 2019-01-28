// This file will hold the nodes for both the location LLL and the job LLL
// This will also hold the class which will hold the constructor and destructor


#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>

using namespace std;

struct job;


struct local{

  char * location;

  local * next;
  job * head2;  // points to jobs for location
};

struct job{

  
  char * compName;
  char * description;
  char * qualifications;
  char * jobSpec;
  char * degree;
  char * review;

  float payRate;
  int rating;

  job * next;
};

class list{
  public:
    list();

    void intro(); // introduction to program

    bool goAgain(); // used for adding locations prompt
    bool yesNo(); // used for yes or no questions


    int buildLocation(); //prompts user for location and jobs wrapper function
    int display(); //displays all jobs

    int displayLocationJobs(); //wrapper, displays jobs at certain location
    int editJobs();

    //~list();
  private:

    int findJob(local * head); // Finds job user is trying edit
    int editJobs_Private(local * & head, char * temp); // Edits found job
    int displayLocationJobsPriv(local * head); // Displays Jobs by Location 
    int displayPrivateJobs(job * head2); // Displays Jobs connected to Location 
    int displayPrivate(local * head); // Displays all jobs 
    int buildLocationNode(); // Builds nodes for Locations
    int buildPrivate_Location(local * & head); // Builds the Locations LLL
    int buildJobNode(local * head); // Builds nodes for Jobs
    int buildPrivate_Jobs(job * & head2); // Builds the Jobs LLL connected to Location

    local * head;



};
