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

    bool goAgain(); // used for question prompts
    bool yesNo();


    int buildLocation(); //prompts user for location and jobs wrapper function
    int display(); //displays all jobs

    int displayLocationJobs(); //wrapper, displays jobs at certain location

    //~list();
  private:

    int displayLocationJobsPriv(local * head);
    int displayPrivateJobs(job * head2);
    int displayPrivate(local * head);
    int buildLocationNode();
    int buildPrivate_Location(local * & head);
    int buildJobNode(local * head);
    int buildPrivate_Jobs(job * & head2);

    local * head;



};
