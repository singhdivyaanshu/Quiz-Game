#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int point=0,point1=0,point2=0,point3=0,point4=0;

class game{ char ec[], mc[], hc[], ans[];
	        void easy();
	        void med();
	        void hard();
	        void bonus();
	        public:
	        void play();
	      }g;

void add()
{ system("cls");
  char more;
  do{ char ques[200], opta[20], optb[20], optc[20], optd[20], ans[20];
      fstream file;
	  cin.ignore();
	  cout<<"Enter Question: ";
      cin.getline(ques,200,'\n');
      cout<<"Enter option A: ";
      cin.getline(opta,200,'\n');
      cout<<"Enter option B: ";
      cin.getline(optb,200,'\n');
      cout<<"Enter option C: ";
      cin.getline(optc,200,'\n');
      cout<<"Enter option D: ";
      cin.getline(optd,200,'\n');
      cout<<"Enter Answer: ";
      cin.getline(ans,200,'\n');
      file.open("ques.txt",ios::out|ios::app);
      file<<ques<<"\n";
      file<<opta<<"\n";
      file<<optb<<"\n";
      file<<optc<<"\n";
      file<<optd<<"\n";
      file<<ans<<"\n";
      file.close();
      cout<<endl<<"Question Added !!"<<endl;
      cout<<"Do you want to add more ? (Y/N): ";
      cin>>more;
      cin.ignore();
    }while(more=='y'||more=='Y');
}

void view()
{ system("cls");
  int qnum=1;
  char ques[200], opta[20], optb[20], optc[20], optd[20], ans[20];
  ifstream file;
  file.open("ques.txt");
  while(!(file.eof()))
  { system("cls");
    Sleep(500);
    file.getline(ques,200,'\n');
    file.getline(opta,20,'\n');
    file.getline(optb,20,'\n');
    file.getline(optc,20,'\n');
    file.getline(optd,20,'\n');
    file.getline(ans,20,'\n');
    cout<<"Question No. "<<qnum<<endl<<endl;
    cout<<"Question: "<<ques<<endl;
    cout<<"Option A: "<<opta<<endl;
    cout<<"Option B: "<<optb<<endl;
    cout<<"Option C: "<<optc<<endl;
    cout<<"Option D: "<<optd<<endl;
    cout<<"Answer: "<<ans<<endl;
    cout<<endl;
    qnum++;
    cout<<"Press Enter to view next..";
    getch();
  }
  file.close();
}

void del()
{   system("cls");
    int ques_num;
    ifstream fin("ques.txt");
    ofstream fout;
    fout.open("temp.txt", ofstream::out);
    char c;
    int line_no = 0;
    cout<<"\nEnter question number you want to delete: ";
    cin>>ques_num;
    while(fin.get(c))
    {

        if(c == '\n')
            line_no++;

        if(line_no <= 6*((ques_num-1) - 1) || line_no > 6*(ques_num-1))
            fout<<c;

    }
    fout.close();
    fin.close();

    remove("ques.txt");
    rename("temp.txt", "ques.txt");
    cout<<endl<<"Question Deleted !!"<<endl;
}

void admin()
{ int choice;
  do{ system("cls");
      int choice;
      cout<<"\n################################################################################\n";
      cout<<"\n                       Welcome to Admin Section !!\n";
      Sleep(2000);
      cout<<"\n                       1. Add Questions\n";
      cout<<"\n                       2. View Questions\n";
      cout<<"\n                       3. Delete Questions\n";
      cout<<"\n                       4. Exit\n";
      Sleep(500);
      cout<<"\n################################################################################\n";
      Sleep(700);
      cout<<"\n\n                       Enter your choice: ";
      cin>>choice;
      switch(choice)
      { case 1: add();
      			break;
      	case 2: view();
     			break;
     	case 3: del();
     			break;
       default: cout<<"Wrong choice.. Try Again !!";
      };
    }while(choice<=3);
}

void game::bonus()
{ system("cls");
  cout<<"\n\t\t\t       ****BONUS LEVEL****\n\n\n";
  Sleep(1000);
  cout<<"\n\t\t\t    ************************";
  cout<<"\n\t\t\t        | INSTRUCTIONS |";
  cout<<"\n\t\t\t    ************************";
  Sleep(800);
  cout<<"\n\n\n";
  cout<<"\n################################################################################\n";
  cout<<"\n\t\t      IT WILL BE A MULTIPLE CHOICE QUESTION\n";
  Sleep(2000);
  cout<<"\n\t\t                   TYPE QUIZ\n";
  Sleep(1000);
  cout<<"\n\t\t    YOU WILL BE PROVIDED SERIES OF QUESTIONS\n";
  Sleep(2000);
  cout<<"\n\t\t               WITH 4 OPTIONS EACH\n";
  Sleep(2000);
  cout<<"\n\t\t  FROM THE 4 OPTIONS ONLY ONE OPTION IS CORRECT\n";
  Sleep(2500);
  cout<<"\n\n################################################################################\n";
  Sleep(1000);
  cout<<"\n\t       5 POINTS WILL BE AWARDED FOR EACH RIGHT ANSWER!!!\n"
      <<"\n\t           DIFFICUTLY LEVEL WILL INCREASE WITH EACH\n"
	  <<"\n\t                    SUBSEQUENT QUESTION !!\n"
	  <<"\n\n################################################################################\n";
  Sleep(5000);
  cout<<"\nPRESS ANY KEY TO CONTINUE";
  getch();
  system("cls");
  ifstream inFile("ques.txt");
  char qs[256],opt1[32],opt2[32],opt3[32],opt4[32],answer;
  int qnum=1;
  while(!(inFile.eof()))
  { inFile.getline(qs,256,'\n');
    inFile.getline(opt1,32,'\n');
    inFile.getline(opt2,32,'\n');
    inFile.getline(opt3,32,'\n');
    inFile.getline(opt4,32,'\n');
    inFile.get(answer);
    inFile.ignore(qnum);
    char userans;
    system("cls");
    cout<<"\n################################################################################\n";
    cout<<"\nQues No. "<<qnum<<"\n\n";
    Sleep(1000);
    puts(qs);
    Sleep(3000);
    cout<<"\n";
    cout<<" A. ";
    puts(opt1);
    Sleep(1000);
    cout<<" B. ";
    puts(opt2);
    Sleep(1000);
    cout<<" C. ";
    puts(opt3);
    Sleep(1000);
    cout<<" D. ";
    puts(opt4);
    Sleep(1000);
    cout<<"\n################################################################################\n";
    cout<<"\nEnter Your Answer : ";
    cin>>userans;
    if(userans==answer)
    { cout<<"\nYOU ARE RIGHT YOU GET 5 POINTS !!\n";
      point4+=5;
      Sleep(2000);
      cout<<"\nPRESS ANY KEY TO CONTINUE";
    }
    else
    { cout<<"\nWRONG ANSWER !! BETTER LUCK NEXT TIME !!\n";
      Sleep(2000);
      cout<<"PRESS ANY KEY TO CONTINUE";
    }
    qnum++;
  }
  inFile.close();
  system("cls");
  point=point1+point2+point3+point4;
  cout<<"\n\n\n\n\n\n\n";
  cout<<"\n\n\t\t\t    ------------------------";
  cout<<"\n\n\t\t\t     YOUR TOTAL SCORE : "<<point;
  cout<<"\n\n\t\t\t    ------------------------";
  cout<<"\n\n\n";
  Sleep(2000);
  if(point==100)
  { cout<<"\t\tNo Cheating... You Have Done This Earlier Also !!"; }
  else if(point==90)
       { cout<<"\t\t\tYou Are Extremely Intelligent !!"; }
       else if(point==80)
	        { cout<<"\t\t\t     You Are Intelligent !!"; }
	        else if((point==70)||(point==60)||(point==50))
		         { cout<<"\t\t   You Are Average... Better Luck Next Time !!"; }
		         else if(point<=40)
		              { cout<<"\t\t\t  You Need to Practice More !!"; }
  Sleep(2000);
  cout<<"\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
  getch();
}

void game::play()
{ easy();
  if(point1>=10)
  { med();
    if(point2>=20)
    { hard();
      if(point3>=30)
      { system("cls");
	    cout<<"\n\n\n\n\n\n################################################################################\n";
     	cout<<"\n\n\n\t\t\t\tLEVEL 3 CLEARED!!!\n";
	    cout<<"\n\n\n\n################################################################################\n";
    	Sleep(3000);
    	cout<<"PRESS ENTER TO CONTINUE";
    	getch();
    	system("cls");
    	point=point1+point2+point3+point4;
    	cout<<"\n\n\n\n\n\n\n";
    	cout<<"\n\n\t\t\t    ------------------------";
    	cout<<"\n\n\t\t\t     YOUR TOTAL SCORE : "<<point;
    	cout<<"\n\n\t\t\t    ------------------------";
    	cout<<"\n\n\n";
    	Sleep(2000);
    	if(point==100)
    	{ cout<<"\t\tNo Cheating... You Have Done This Earlier Also !!"; }
	    else if(point==90)
	         { cout<<"\t\t\tYou Are Extremely Intelligent !!"; }
	         else if(point==80)
	    	      cout<<"\t\t\t     You Are Intelligent !!";
		          else if((point==70)||(point==60)||(point==50))
		               { cout<<"\t\t   You Are Average... Better Luck Next Time !!"; }
		               else if(point<=40)
			                { cout<<"\t\t\t  You Need to Practice More !!"; }
        Sleep(2000);
	    cout<<"\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
        getch();
     	if(point<=50)
	    { system("cls");
	      char cht;
	      cout<<"\n\n\n\n\n\n################################################################################\n";
	      cout<<"\n\n\n\t\t     DO YOU WANT TO IMPROVE YOUR RESULT ?\n";
	      cout<<"\n\n\n\n################################################################################\n";
	      cout<<"\n\t\t    ENTER 'Y' FOR YES OR 'N' FOR NO : ";
	      cin>>cht;
	      if(cht=='Y'||cht=='y')
	      { bonus(); }
	    }
      }
      else
      { system("cls");
	    cout<<"\n\n\n\n\n\n################################################################################\n";
	    cout<<"\n\n\n\t\t\t\tLEVEL 3 FAILED!!!\n";
	    cout<<"\n\n\n\n################################################################################\n";
	    Sleep(3000);
	    cout<<"PRESS ENTER TO CONTINUE";
	    getch();
	    system("cls");
     	point=point1+point2+point3+point4;
	    cout<<"\n\n\n\n\n\n\n";
	    cout<<"\n\n\t\t\t    ------------------------";
	    cout<<"\n\n\t\t\t     YOUR TOTAL SCORE : "<<point;
	    cout<<"\n\n\t\t\t    ------------------------";
	    cout<<"\n\n\n";
	    Sleep(2000);
	    if(point==100)
	    { cout<<"\t\tNo Cheating... You Have Done This Earlier Also !!"; }
	    else if(point==90)
    	     { cout<<"\t\t\tYou Are Extremely Intelligent !!"; }
    	     else if(point==80)
        		  { cout<<"\t\t\t     You Are Intelligent !!"; }
		          else if((point==70)||(point==60)||(point==50))
		               { cout<<"\t\t   You Are Average... Better Luck Next Time !!"; }
		               else if(point<=40)
			                { cout<<"\t\t\t  You Need to Practice More !!"; }
	    Sleep(2000);
	    cout<<"\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
	    getch();
	    if(point<=50)
	    { bonus(); }
      }
    }
    else
    { system("cls");
      cout<<"\n\n\n\n\n\n################################################################################\n";
      cout<<"\n\n\n\t\t\t\tLEVEL 2 FAILED!!!\n";
      cout<<"\n\n\n\n################################################################################\n";
      Sleep(3000);
      cout<<"PRESS ENTER TO CONTINUE";
      getch();
      system("cls");
      point=point1+point2+point3+point4;
      cout<<"\n\n\n\n\n\n\n";
      cout<<"\n\n\t\t\t    ------------------------";
      cout<<"\n\n\t\t\t     YOUR TOTAL SCORE : "<<point;
      cout<<"\n\n\t\t\t    ------------------------";
      cout<<"\n\n\n";
      Sleep(2000);
      if(point==100)
      { cout<<"\t\tNo Cheating... You Have Done This Earlier Also !!"; }
      else if(point==90)
	       { cout<<"\t\t\tYou Are Extremely Intelligent !!"; }
	       else if(point==80)
		        { cout<<"\t\t\t     You Are Intelligent !!"; }
		        else if((point==70)||(point==60)||(point==50))
		             { cout<<"\t\t   You Are Average... Better Luck Next Time !!"; }
		             else if(point<=40)
			              { cout<<"\t\t\t  You Need to Practice More !!"; }
      Sleep(2000);
      cout<<"\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
      getch();
      if(point<=50)
      { bonus(); }
    }
  }
  else
    { system("cls");
      cout<<"\n\n\n\n\n\n################################################################################\n";
      cout<<"\n\n\n\t\t\t\tLEVEL 1 FAILED!!!\n";
      cout<<"\n\n\n\n################################################################################\n";
      Sleep(3000);
      cout<<"PRESS ENTER TO CONTINUE";
      getch();
      system("cls");
      point=point1+point2+point3+point4;
      cout<<"\n\n\n\n\n\n\n";
      cout<<"\n\n\t\t\t    ------------------------";
      cout<<"\n\n\t\t\t     YOUR TOTAL SCORE : "<<point;
      cout<<"\n\n\t\t\t    ------------------------";
      cout<<"\n\n\n";
      Sleep(2000);
      if(point==100)
      { cout<<"\t\tNo Cheating... You Have Done This Earlier Also !!"; }
      else if(point==90)
	       { cout<<"\t\t\tYou Are Extremely Intelligent !!"; }
	       else if(point==80)
		        { cout<<"\t\t\t     You Are Intelligent !!"; }
		        else if((point==70)||(point==60)||(point==50))
		             { cout<<"\t\t   You Are Average... Better Luck Next Time !!"; }
		             else if(point<=40)
			              { cout<<"\t\t\t  You Need to Practice More !!"; }
      Sleep(2000);
      cout<<"\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
      getch();
      if(point<=50)
      { bonus(); }
    }
}

void game::easy()
{ system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\tFOR CLEARING LEVEL 1 YOU NEED TO SCORE ATLEAST 10 POINTS !!";
  Sleep(4500);
  system("cls");
  cout<<"\n\t\t\t\t****LEVEL-1****\n\n\n";
  Sleep(1000);
  cout<<"\n\t\t\t   ************************";
  cout<<"\n\t\t\t       | INSTRUCTIONS |";
  cout<<"\n\t\t\t   ************************";
  Sleep(800);
  cout<<"\n\n\n"
      <<"\n################################################################################\n";
  cout<<"\n\t    THE LOGIC BEHIND THIS LEVEL IS THAT YOU NEED TO GUESS\n";
  Sleep(2500);
  cout<<"\n\t          THE MISSING CONSONANTS IN THE GIVEN WORD\n";
  Sleep(2500);
  cout<<"\n\t        BUT THE INTERESTING PART IS THAT YOU NEED TO\n";
  Sleep(2500);
  cout<<"\n\t      GUESS ALL THE CONSONANTS IN ONE GO AS PER THEIR\n";
  Sleep(2500);
  cout<<"\n\t                   ORDER OF OCCURENCE!!\n";
  Sleep(1500);
  cout<<"\n\n\n\t		   -------------------"
      <<"\n\t                       FOR EXAMPLE"
      <<"\n\t		   -------------------\n"
      <<"\n\t                        _O_PU_E_\n";
  Sleep(4000);
  cout<<"\n\t    THE WORD IS : COMPUTER. SO WHILE GUESSING YOU SHOULD\n";
  Sleep(3000);
  cout<<"\n\t            FIRST SAY C, THEN M,T AND AT LAST R\n";
  Sleep(8000);
  cout<<"\n################################################################################\n";
  cout<<"                 IF A CONSONANT IS REPEATING IN THE GIVEN WORD THEN \n"
      <<"\n              YOU MUST ENTER IT TWICE AS PER ITS ORDER OF OCCURENCE";
  cout<<"\n\n";
  cout<<"\n          NOTE : CHANCES TO GUESS = TOTAL NO OF BLANKS IN THE GIVEN WORD\n"
      <<"\n################################################################################\n";
  Sleep(10000);
  cout<<"PRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  char ec1[]={'t','w','t','r'};
  int ec2=0;
  Sleep(1000);
  system("cls");
  cout<<"\n\n###############################################################################\n";
  cout<<"\n\t\t\tYOU HAVE 1 CHANCE FOR EACH BLANK\n";
  Sleep(1500);
  cout<<"\n\t\t\t     ENTER ALL YOUR CHOICES\n";
  Sleep(1500);
  cout<<"\n\t\t\t            IN ONE GO\n";
  Sleep(1500);
  cout<<"\n\t       IF A CONSONANT IS REPEATING IN THE GIVEN WORD THEN\n";
  Sleep(2000);
  cout<<"\n\t     YOU MUST ENTER IT TWICE AS PER ITS ORDER OF OCCURENCE\n";
  cout<<"\n################################################################################\n\n";
  Sleep(3000);
  cout<<"PRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\n\t\t\t   LETS BEGIN THE GAME !!!!";
  Sleep(2000);
  cout<<"\n\n\n\t\t\t           __I_TE_\n";
  Sleep(1000);
  cout<<"\n\t\t(LARRY BIRD IS THE LOGO OF WHICH FAMOUS COMPANY)\n\n";
  Sleep(8000);
  cout<<"ENTER ANSWERS :\n";
  for(int e=0;e<4;e++)
  { cout<<"\nBLANK "<<e+1<<" : ";
    cin>>ec[e];
  }
  for(int e1=0;e1<4;e1++)
  { if(ec1[e1]==ec[e1])
    { ec2++; }
  }
  if(ec2==4)
  { point1=point1+10;
    cout<<"\n\nALL ARE CORRECT !! YOU GET 10 POINTS !!!";
    cout<<"\n\nTHE WORD IS : TWITTER";
  }
  else
  { cout<<"\n\nBLANK ";
    for(int e1=0;e1<4;e1++)
    { if(ec1[e1]==ec[e1])
      { continue; }
      else
      { cout<<e1+1<<" "; }
    }
    cout<<"IS/ARE INCORRECT !!";
    cout<<"\n\nTHE WORD IS : TWITTER";
    cout<<"\n\nYOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  char mc1[]={'l','k'};
  int mc2=0;
  Sleep(1000);
  cout<<"\n\n\n\t\t\t\t      _I_E\n";
  Sleep(1000);
  cout<<"\n\t      (IF YOU +1 ON GOOGLE+, THEN WHAT IS IT ON FACEBOOK)\n\n";
  Sleep(8000);
  cout<<"ENTER ANSWERS :\n";
  for(int m=0;m<2;m++)
  { cout<<"\nBLANK "<<m+1<<" : ";
    cin>>mc[m];
  }
  for(int m1=0;m1<2;m1++)
  { if(mc1[m1]==mc[m1])
    { mc2++; }
  }
  if(mc2==2)
  { point1=point1+10;
    cout<<"\n\nALL ARE CORRECT !! YOU GET 10 POINTS !!!";
    cout<<"\n\nTHE WORD IS : LIKE";
  }
  else
  { cout<<"\n\nBLANK ";
    for(int m1=0;m1<2;m1++)
    { if(mc1[m1]==mc[m1])
      { continue; }
      else
      { cout<<m1+1<<" "; }
    }
    cout<<"IS/ARE INCORRECT !!";
    cout<<"\n\nTHE WORD IS : LIKE";
    cout<<"\n\nYOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  char hc1[]={'r','c','l'};
  int hc2=0;
  Sleep(1000);
  cout<<"\n\n\n\t\t\t\t     O_A__E\n";
  Sleep(1000);
  cout<<"\n\t  (SUN MICROSYSTEMS HAS BEEN ACQUIRED BY WHICH FAMOUS COMPANY)\n\n";
  Sleep(8000);
  cout<<"ENTER ANSWERS :\n";
  for(int h=0;h<3;h++)
  { cout<<"\nBLANK "<<h+1<<" : ";
    cin>>hc[h];
  }
  for(int h1=0;h1<3;h1++)
  { if(hc1[h1]==hc[h1])
    { hc2++; }
  }
  if(hc2==3)
  { point1=point1+10;
    cout<<"\n\nALL ARE CORRECT !! YOU GET 10 POINTS !!!";
    cout<<"\n\nTHE WORD IS : ORACLE";
  }
  else
  { cout<<"\n\nBLANK ";
    for(int h1=0;h1<3;h1++)
    { if(hc1[h1]==hc[h1])
      { continue; }
      else
      { cout<<h1+1<<" "; }
    }
    cout<<"IS/ARE INCORRECT !!";
    cout<<"\n\nTHE WORD IS : ORACLE";
    cout<<"\n\nYOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\tYOUR TOTAL SCORE OF LEVEL 1 : "<<point1<<endl;
  Sleep(2000);
  cout<<"\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
  getch();
}

void game::med()
{ system("cls");
  cout<<"\n\n\n\n\n\n\n\n";
  cout<<"\n\n\n\t\t\tYOU HAVE QUALIFIED FOR LEVEL 2 !!\n\n\n";
  cout<<"\n\n\t\t\t\t  PLEASE WAIT!!\n\n\n";
  Sleep(4500);
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t    FOR CLEARING LEVEL 2 YOU NEED TO SCORE ATLEAST 20 POINTS !!";
  Sleep(3000);
  system("cls");
  cout<<"\n\t\t\t        ****LEVEL-2****\n\n\n";
  Sleep(1000);
  cout<<"\n\t\t\t   ************************";
  cout<<"\n\t\t\t       | INSTRUCTIONS |";
  cout<<"\n\t\t\t   ************************";
  Sleep(800);
  cout<<"\n\n\n"
      <<"\n################################################################################\n";
  cout<<"\t\t     THERE WILL BE A SEQUENCE OF WORDS\n";
  Sleep(2000);
  cout<<"\n\t\t     WHICH WILL VANISH IN A FEW SECONDS\n";
  Sleep(2000);
  cout<<"\n\t\t     YOU NEED TO REMEMBER ALL THE WORDS\n";
  Sleep(2000);
  cout<<"\n\t\t   OF THE SEQUENCE, THEN YOU NEED TO GIVE\n";
  Sleep(2000);
  cout<<"\n\t\t   ONE WORD FROM THE SEQUENCE OF WORDS YOU\n";
  Sleep(2000);
  cout<<"\n\t\t HAVE OBSERVED EARLIER FOR THE MEANING ASKED!!\n";
  Sleep(2000);
  cout<<"\n################################################################################\n";
  Sleep(1000);
  cout<<"\n\t      10 POINTS WILL BE AWARDED FOR EACH RIGHT ANSWER !!!\n";
  cout<<"\n\t           DIFFICULTY LEVEL WILL INCREASE WITH EACH";
  cout<<"\n\n\t                   SUBSEQUENT QUESTION !!!\n\n\n";
  cout<<"\n################################################################################\n";
  Sleep(5000);
  cout<<"PRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  //loading();
  int x;
  Sleep(1000);
  for(x=3;x>=0;x--)
  { system("cls");
    cout<<"\n\n\n\n\t\t\t\t       ##1";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\tARE YOU READY ? "<<x;
    Sleep(1500);
  }
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##1";
  cout<<"\n\n\n";
  cout<<"\n################################################################################";
  cout<<"\n\n\t\t\t  MINUTE, CUP, ANT, DISK, CHIP\n";
  cout<<"\n\n################################################################################\n";
  Sleep(5000);
  system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\n\t\t\t WRITE WORD FOR THE MEANING !!\n\n\n";
  Sleep(2000);
  cout<<"\t\t      ----------------------------------";
  cout<<"\n\t\t       INFINITELY OR IMMEASURABLY SMALL";
  cout<<"\n\t\t      ----------------------------------";
  Sleep(2000);
  cout<<"\n\n\n\n\t\t\t      ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t            ";
  cin>>ans;
  if(!strcmpi(ans,"minute"))
  { point2=point2+10;
    cout<<"\n\n\t\t    YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t              ANSWER IS : MINUTE";
  }
  else
  { cout<<"\n\n\t\t  YOU ARE WRONG, RIGHT ANSWER IS : MINUTE !!";
    cout<<"\n\n\t\t              YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  for(x=3;x>=0;x--)
  { system("cls");
    cout<<"\n\n\n\n\t\t\t\t       ##2";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\tARE YOU READY ? "<<x;
    Sleep(1500);
  }
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##2";
  cout<<"\n\n\n";
  cout<<"\n################################################################################";
  cout<<"\n\n\t       ESTABLISH, DEMORALIZE, PROJECT, TELLURIUM, DISTANCE\n";
  cout<<"\n\n################################################################################\n";
  Sleep(5000);
  system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\n\t\t\t WRITE WORD FOR THE MEANING !!\n\n\n";
  Sleep(2000);
  cout<<"\t\t           -----------------------";
  cout<<"\n\t\t            A PLANNED UNDERTAKING";
  cout<<"\n\t\t           -----------------------";
  Sleep(2000);
  cout<<"\n\n\n\n\t\t\t      ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t            ";
  cin>>ans;
  if(!strcmpi(ans,"project"))
  { point2=point2+10;
    cout<<"\n\n\t\t    YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t              ANSWER IS : PROJECT";
  }
  else
  { cout<<"\n\n\t\t  YOU ARE WRONG, RIGHT ANSWER IS : PROJECT !!";
    cout<<"\n\n\t\t              YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  for(x=3;x>=0;x--)
  { system("cls");
    cout<<"\n\n\n\n\t\t\t\t       ##3";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\tARE YOU READY ? "<<x;
    Sleep(1500);
  }
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##3";
  cout<<"\n\n\n";
  cout<<"\n################################################################################";
  cout<<"\n\n\t          EXECRATE, GLUTINOUS, ALACRITY, FOIBLE, SKILL\n";
  cout<<"\n\n################################################################################\n";
  Sleep(5000);
  system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\n\t\t\t WRITE WORD FOR THE MEANING !!\n\n\n";
  Sleep(2000);
  cout<<"\t\t-----------------------------------------------";
  cout<<"\n\t\t AN ABILITY THAT HAS BEEN ACQUIRED BY TRAINING";
  cout<<"\n\t\t-----------------------------------------------";
  Sleep(2000);
  cout<<"\n\n\n\n\t\t\t      ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t            ";
  cin>>ans;
  if(!strcmpi(ans,"skill"))
  { point2=point2+10;
    cout<<"\n\n\t\t    YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t              ANSWER IS : SKILL";
  }
  else
  { cout<<"\n\n\t\t  YOU ARE WRONG, RIGHT ANSWER IS : SKILL !!";
    cout<<"\n\n\t\t              YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\tYOUR TOTAL SCORE OF LEVEL 2 : "<<point2<<endl;
  Sleep(2000);
  cout<<"\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
  getch();
}

void game::hard()
{ system("cls");
  cout<<"\n\n\n\n\n\n\n\n";
  cout<<"\n\n\n\t\t\tYOU HAVE QUALIFIED FOR LEVEL 3 !!\n\n\n";
  cout<<"\n\n\t\t\t\t  PLEASE WAIT !!\n\n\n";
  Sleep(4500);
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t    FOR CLEARING LEVEL 3 YOU NEED TO SCORE ATLEAST 30 POINTS !!";
  Sleep(3000);
  system("cls");
  cout<<"\n\t\t\t        ****LEVEL-3****\n\n\n";
  Sleep(1000);
  cout<<"\n\t\t\t   ************************";
  cout<<"\n\t\t\t       | INSTRUCTIONS |";
  cout<<"\n\t\t\t   ************************";
  Sleep(800);
  cout<<"\n\n\n";
  cout<<"\n################################################################################\n";
  cout<<"\t\t        THERE WILL BE A JUMBLED WORD\n";
  Sleep(2000);
  cout<<"\n\t\t    YOU NEED TO UNJUMBLE THE JUMBLED WORD\n";
  Sleep(2000);
  cout<<"\n################################################################################\n";
  cout<<"\n\t\t 10 POINTS WILL BE AWARDED FOR EACH RIGHT ANSWER!!!\n";
  cout<<"\n\t\t       DIFFICULTY LEVEL WILL INCREASE WITH EACH";
  cout<<"\n\n\t\t               SUBSEQUENT QUESTION !!\n\n\n";
  cout<<"\n################################################################################\n";
  Sleep(5000);
  cout<<"PRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##1";
  cout<<"\n\n\n";
  Sleep(800);
  cout<<"\t\t                    ----------";
  cout<<"\n\t\t                     ERNTTNEI";
  cout<<"\n\t\t                    ----------";
  Sleep(2000);
  cout<<"\n\n\t\t(A GLOBOL NETWORK CONNECTING MILLIONS OF COMPUTERS)";
  Sleep(4000);
  cout<<"\n\n\n\n\t\t\t        ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t             ";
  cin>>ans;
  if(!strcmpi(ans,"internet"))
  { point3=point3+10;
    cout<<"\n\n\t\t      YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t               ANSWER IS : INTERNET";
  }
  else
  { cout<<"\n\n\t\t   YOU ARE WRONG, RIGHT ANSWER IS : INTERNET !!";
    cout<<"\n\n\t\t                YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##2";
  cout<<"\n\n\n";
  Sleep(800);
  cout<<"\t\t                   ------------";
  cout<<"\n\t\t                    NNTNOVOAII";
  cout<<"\n\t\t                   ------------";
  Sleep(2000);
  cout<<"\n\n\t\t        (A NEW METHOD, IDEA, PRODUCT, ETC)";
  Sleep(4000);
  cout<<"\n\n\n\n\t\t\t        ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t            ";
  cin>>ans;
  if(!strcmpi(ans,"innovation"))
  { point3=point3+10;
    cout<<"\n\n\t\t       YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t               ANSWER IS : INNOVATION";
  }
  else
  { cout<<"\n\n\t\t  YOU ARE WRONG, RIGHT ANSWER IS : INNOVATION !!";
    cout<<"\n\n\t\t                YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##3";
  cout<<"\n\n\n";
  Sleep(800);
  cout<<"\t\t                 ---------------";
  cout<<"\n\t\t                  UOIINNOMMTACC";
  cout<<"\n\t\t                 ---------------";
  Sleep(2000);
  cout<<"\n\n\t\t   (MEANS OF SENDING OR RECIEVING INFORMATION)";
  Sleep(4000);
  cout<<"\n\n\n\n\t\t\t        ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t          ";
  cin>>ans;
  if(!strcmpi(ans,"communication"))
  { point3=point3+10;
    cout<<"\n\n\t\t      YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t             ANSWER IS : COMMUNICATION";
  }
  else
  { cout<<"\n\n\t\tYOU ARE WRONG, RIGHT ANSWER IS : COMUNICATION !!";
    cout<<"\n\n\t\t                YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\t\t\t\t       ##4";
  cout<<"\n\n\n";
  Sleep(800);
  cout<<"\t\t                   ----------";
  cout<<"\n\t\t                    ERESAHRC";
  cout<<"\n\t\t                   ----------";
  Sleep(2000);
  cout<<"\n\n\t\t          (INVESTIGATE SYSTEMATICALLY)";
  Sleep(4000);
  cout<<"\n\n\n\n\t\t\t       ENTER YOUR ANSWER :\n";
  cout<<"\n\t\t\t            ";
  cin>>ans;
  if(!strcmpi(ans,"research"))
  { point3=point3+10;
    cout<<"\n\n\t\t      YOU ARE RIGHT !! YOU GET 10 POINTS !!!";
    cout<<"\n\n\t\t               ANSWER IS : RESEARCH";
  }
  else
  { cout<<"\n\n\t\t  YOU ARE WRONG, RIGHT ANSWER IS : RESEARCH !!";
    cout<<"\n\n\t\t               YOU GET 0 POINTS !!";
  }
  Sleep(3000);
  cout<<"\n\nPRESS ENTER TO CONTINUE";
  getch();
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\tYOUR TOTAL SCORE OF LEVEL 3 : "<<point3<<endl;
  Sleep(2000);
  cout<<"\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE";
  getch();
}

int main()
{ system("cls");
  int choice;
  char ch, name;
  cout<<"\n\n";
  cout<<"\n\n";
  cout<<"\n  _____________________________________________________________________________";
  cout<<"\n  .#######..##.....##.####.#######...#######.##........##.......##.####.#######";
  cout<<"\n  ##.....##.##.....##..##...... #....##......##........##.......##..##.......#.";
  cout<<"\n  ##.....##.##.....##..##......#.....##......##........##.......##..##......#..";
  cout<<"\n  ##.....##.##.....##..##.....#......####....##........##.......##..##.....#...";
  cout<<"\n  ##..#..##.##.....##..##....#.......##......##........##...#...##..##....#....";
  cout<<"\n  ##...#.##.##.....##..##...#........##......##........#####.#####..##...#.....";
  cout<<"\n  .#######...#######..#### #######...#######.#######...####...####.####.#######";
  cout<<"\n  ____________________________________________________________________________";
  Sleep(1000);
  cout<<"\n\n\t\t\t    -----------------------";
  cout<<"\n\t\t\t     >>>TRY GUESSING IT<<<";
  cout<<"\n\t\t\t    -----------------------";
  Sleep(4000);
  system("cls");
  menu:
  do{ system("cls");
      cout<<"\n_____________________________________________________________________________";
      cout<<"\n|.##.....##....###....####.##....##....##.....##.########.##....##.##.....##|";
      cout<<"\n|.###...###...##.##....##..###...##....###...###.##.......###...##.##.....##|";
      cout<<"\n|.####.####..##...##...##..####..##....####.####.##.......####..##.##.....##|";
      cout<<"\n|.##.###.##.##.....##..##..##.##.##....##.###.##.######...##.##.##.##.....##|";
      cout<<"\n|.##.....##.#########..##..##..####....##.....##.##.......##..####.##.....##|";
      cout<<"\n|.##.....##.##.....##..##..##...###....##.....##.##.......##...###.##.....##|";
      cout<<"\n|.##.....##.##.....##.####.##....##....##.....##.########.##....##..#######.|";
      cout<<"\n_____________________________________________________________________________\n\n\n";
      cout<<"\n############################################################################\n";
      cout<<"\n\n\t\t\t     -------------";
      cout<<"\n\t\t\t        1. PLAY";
      cout<<"\n\t\t\t        2. ADMIN";
      cout<<"\n\t\t\t        3. EXIT";
      cout<<"\n\t\t\t     -------------";
      cout<<"\n\n";
      cout<<"############################################################################";
      cout<<"\n\n\n\t\t\t Enter Your Choice :\t";
      cin>>choice;
      system("cls");
      switch(choice)
      { case 1: g.play();
		        break;
		case 2: admin();
		        goto menu;
				break;
	    case 3: exit(0);
	        	break;
       default: cout<<"\n\t\t\tWRONG CHOICE !!!";
		        goto menu;
      }
      system("cls");
      cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t   ---------------------------\n\n";
      cout<<"\t\t\t     WANT TO PLAY MORE ? : ";
      cin>>ch;
      cout<<"\n\t\t\t   ---------------------------";
      Sleep(1000);
      cout<<"\n\n\n\n\n\t\t\t\t  PLEASE WAIT !!";
      Sleep(2000);
      system("cls");
    }while(ch=='y'||ch=='Y');
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t Developed By :"<<endl;
    cout<<"\n\n\t\t\t Divyanshu Singh & Farhan Raja"<<endl;
    cout<<"\n\t\t\t    (2K19/SE/040)   (2K19/SE/041)"<<endl;
    return 0;
	getch();
}
