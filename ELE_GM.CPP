/*
Kids are playing a game of Elimination. The rules of the game are
a) Suppose there are M kids. They stand in a circle and pick a random number N which is less than M.
b) They start counting from 1 to N and the kid at position N is eliminated. They resume counting from position N + 1 starting
from 1.
c) This continues until there is only one kid left. The last Kid standing is declared the Winner.
Write an algorithm which, given values of M and N, identifies the position which would make her the winner.
*/

#include<conio.h>
#include<stdio.h>
#include<iostream.h>



int a[30];

struct node
{
  int info;
  struct node *link;
};


struct node* elm_player(struct node* temp,int N)
{
	int cnt;
	struct node *pre;
	for(cnt = 1;cnt<N;cnt++)
	{
		pre = temp;
		temp = (temp->link);	// traversing in list
	}
	(pre->link) = (temp->link);
	cout<<"\n Player at positon  "<<(temp->info)<<" is eliminated.";
	temp = (temp->link);	//(N+1)th element
	
	return temp;
	
}

void winner(int M,int N)
{
	struct node *start,*add,*temp;
	int i,cnt = 1;
	
	// Creating List that indicates M position
	start=new node;		// First node
	if(start=='\0')
	{
		cout<<"\n No Free Node...\n";
	}	
	else
	{
		start->info = 1;			// Storing 1 indicating position 1
		temp = start;
		(temp->link)=start;	    // This is done as we want Circle, i.e. Circular List
		
		for(i=2;i<=M;i++)
		{		
			add=new node;
			if(add=='\0')
			   cout<<"\n No Free Node...\n";
			else
			{				
				(add->info)=i;		// i is stored as info
				(add->link)=(temp->link);	// Linking new node at the end of the list of existing nodes
				(temp->link)=add;			// Done
				temp = add;		// Temp is now pointing to newly added node.
			}				
		}
	}
	// List is created.
	
	// Now eliminating one by one.
	temp = start;	// For first pass, we will start from 1.
	while(cnt != M)
	{
		temp = elm_player(temp,N);   // temp is updated to point N+1 player for next passes
		cnt += 1;		// Counter for counting no.of passes. 
	}
	
	/* When cnt = M, there is only one player remains in game. He/She is winner & is pointed by temp */

cout<<"\n\n Congratulations……\n Player at position "<<(temp->info)<<" is winner.\n";
	
}

int main()
{
	int M,N;	
	
	
	// IMPLEMENTATION OF ELIMINATION GAME 
	
	do
	{
	cout<<"\n Enter number of players.(Maximum 30 and for exit Enter 0): ";
	cin>>M;
		if(M == 0)
		{
			cout<<"\n Exit.";
			break;
		}
		if(M < 2 || M > 30)
		{
			cout<<"\n Invalid Input. Try Again.\n";
		}	
		else
		{
			cout<<"\n Enter Elimination Value (Must be less than "<<M<<"): ";							// N must be less than M
			cin>>N;
			if(N>=M)
				cout<<"\n Invalid Data. Try Again.\n";
			else
				winner(M,N);
		}
	}while(M!=0);
		
	return 1;
}

/* Explation:-
This program is written in c++ language. Here structure is used that is globally created. In node info that contain information(value) and link hold the next node.  elm_player() is function for eliminating players and winner() is function for winner. M is total number of players and N is number that randomly choose.

In elm_player() 
-Here temp (structure node) and N are passed as parameter.
-Here temp is transfer to pre node and temp hold the next node. 
-so by traversing the list up to N, temp is copied into temporary pre node 
And the next node that linked by temp is hold by temp. means pre node contain the player that is eliminated.

In winner()
-M and N are passed as parameter .
-Here three nodes add, temp and start are created.
-start for starting node, temp is temporary purpose and add is for adding new node.
-Here cnt is used for counting purpose ,start from 1 to M.
-After that elm_player function is called, that eliminate the Nth player and 
Cnt increase by 1 again call elm_player function till winner is found.

In main()
-do while loop is used , M and N are entered explicitly and winner function is called automatically.*/
