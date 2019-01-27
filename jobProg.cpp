// This file will build all my functions from the .h file and 
// build the constuctors and destructors of the linear linked lists



#include "job.h" // brings in .h file


// initiates list build and sets location and job heads to NULL
list::list(){


  head = NULL;
  //head2 = NULL;

}
// this will search for a certain location that user needs
int list::displayLocationJobsPriv(local * head)
{
  if(!head) return -1;

  job * curr = head->head2; // creates pointer to head2 point for job list

  char * temp = new char[20];
  cout << "Please enter the Location you are looking for to display jobs: ";
  cin.get(temp,20);
  cin.ignore(100,'\n');
  
  while(head->next)
  {
      if(strcmp(temp,head->location) != 0) 
      {
        head = head->next;
        curr = head->head2;

      }

  }
  if(strcmp(temp,head->location) != 0)
  {
    cout << "NO MATCHES" << endl;
    return -1;
  }
  cout << "Jobs in " << head->location << endl; 

  while(curr)
  {
    displayPrivateJobs(curr);
    curr = curr->next;
  }

  return 1;


}
// wrapper function to access certain jobs by location
int list::displayLocationJobs()
{
  displayLocationJobsPriv(head);

}
int list::buildPrivate_Jobs(job * & head2)
{
  cout << "Please enter the name of the Company: ";
  char * temp = new char[20];
  cin.get(temp,20);
  cin.ignore(100,'\n');
  head2->compName = new char[strlen(temp) + 1];
  strcpy(head2->compName,temp);
  cout << endl;

 /* cout << "Please enter the job description: ";
  char * temp2 = new char[100];
  cin.get(temp2,100);
  cin.ignore(100,'\n');
  head2->description = new char[strlen(temp2) + 1];
  strcpy(head2->description,temp2);
  cout << endl;

  cout << "Please enter qualifications required(e.g. C++, Java): ";
  cin.get(temp2,100);
  cin.ignore(100,'\n');
  head2->qualifications = new char[strlen(temp2) + 1];
  strcpy(head2->qualifications,temp2);
  cout << endl;

  cout << "Please enter job type(e.g. Internship, Permanent): ";
  cin.get(temp,20);
  cin.ignore(100,'\n');
  head2->jobSpec = new char[strlen(temp) + 1];
  strcpy(head2->jobSpec,temp);
  cout << endl;

  cout << "Please enter degree required(e.g. Associate, Bachelor): ";
  cin.get(temp,20);
  cin.ignore(100,'\n');
  head2->degree = new char[strlen(temp)+1];
  strcpy(head2->degree,temp);
  cout << endl;

  cout << "Please enter the monthly salary: ";
  cin >> head2->payRate;
  cin.ignore(100,'\n');
  cout << endl;

  cout << "Please enter a rating 1 for worst 5 for best: ";
  cin >> head2->rating;
  cin.ignore(100,'\n');
  cout << endl;

  cout << "Please write a small review for the company: ";
  cin.get(temp2,100);
  cin.ignore(100,'\n');
  head2->review = new char[strlen(temp2)+1];
  strcpy(head2->review,temp2);
  cout << endl; */

  head2->next = NULL;

}
// builds the job node 
int list::buildJobNode(local * headLoc)
{
  if(!headLoc->head2)// changed head to headLoc was mixing up pointers
  {
    headLoc->head2 = new job;
    buildPrivate_Jobs(headLoc->head2);
    cout << endl;
    return 1;
  }

  job * current = headLoc->head2;

  while(current->next)
  {
    current = current->next;
  }
  current->next = new job;
  current = current->next;
  buildPrivate_Jobs(current);
  current->next = NULL;

  cout << endl << endl;


}
// wrapper function to keep data private
int list::display()
{
  displayPrivate(head);
}
// runs display
int list::displayPrivate(local * head){

  if(!head) return -1;

  cout << "LOCATION:" << endl;
  cout << head->location << endl << endl;
  job * curr = head->head2;

  cout << "JOBS:" << endl;
  while(curr)
  {
    displayPrivateJobs(curr);
    curr = curr->next;
  }
  displayPrivate(head->next);
  cout << endl;

  return 1;


}
int list::displayPrivateJobs(job * headJob)
{
  if(!headJob) return -1;

  cout << "Company Name: " << endl;
  cout << headJob->compName << endl;
  return 1;

}
// yes or no 
bool list::yesNo(){

  bool temp = true;
  char noYes = ' ';

  cin.get(noYes);
  cin.ignore(100, '\n');

  if(toupper(noYes) == 'Y')
    return true;
  else return false;
}
// Builds the location node privately
int list::buildPrivate_Location(local * & headLoc){

  char reply = 'Y';

    cout << "Please enter the name of the Location: ";
    char * temp = new char[20];
    cin.get(temp, 20);
    cin.ignore(100, '\n');
    headLoc->location = new char[strlen(temp) + 1];
    strcpy(headLoc->location, temp);

    headLoc->next = NULL;


  
  cout << "Now enter jobs: \n";
  while(reply == 'Y')
  {
    buildJobNode(headLoc);
    cout << "Would you like to add another job Y/N: ";
    cin >> reply;
    cin.ignore(100,'\n');
    reply = toupper(reply);
    cout << endl;
  }

}
//go again function for location add
bool list::goAgain(){

  char temp;

  cout << "Would you like to add another location Y/N? ";
  cin.get(temp);
  cin.ignore(100, '\n');

  if(toupper(temp) == 'Y')
    return true;

  else return false;




}
int list::buildLocation(){

  buildLocationNode();

}
// Build location lll
int list::buildLocationNode(){

  if(!head)
  {
    head = new local; // builds new location node if list is currently empty
    buildPrivate_Location(head);
    cout << endl;
    return 0;
  }

  local * current = head;

  while(current->next != NULL)
  {
    current = current->next;

  }
  current->next = new local;
  current = current->next;
  buildPrivate_Location(current);
  current->next = NULL;

  cout << endl;
}
// Intro to program 
void list::intro(){

  cout << "Welcome to the job builder program.  This program will prompt you to enter \n"
       << "locations of the jobs you are looking for.  The program will then prompt you \n"
       << "to enter the jobs and their information (rating, requirements, etc.). When \n"
       << "you are done entering the program will then load this information to a file \n"
       << "for later use." << endl << endl << endl;

}

