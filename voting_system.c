#include<stdio.h>
#include<string.h>

int option = 0 ;
int penVote = 0 , spoonVote = 0, deerVote = 0, lightVote = 0;
int number = 0;

void castvote(){
    int candidate;
    printf("Select you candidate : 1.pen 2.spoon 3.deer 4.light : ");
    scanf("%d",&candidate);
    switch (candidate)
    {
    case 1:
        penVote++;    
        break;
    case 2:
        spoonVote++;
        break;
    case 3:
        deerVote++;
        break;
    case 4:
        lightVote++;
        break;    
    default:
        break;
    }
}
void votecount(){

    printf(" Pen: %d\n",penVote);
    printf(" Spoon: %d\n", spoonVote);
    printf(" Deer: %d\n",deerVote);
    printf(" Light: %d\n", lightVote);
}
void leadingcandid() {
    if (penVote > spoonVote && penVote > deerVote && penVote > lightVote) {
        printf("Leading Candidate is Pen with %d Votes\n", penVote);
    } else if (spoonVote > penVote && spoonVote > deerVote && spoonVote > lightVote) {
        printf("Leading Candidate is Spoon with %d Votes\n", spoonVote);
    } else if (deerVote > penVote && deerVote > spoonVote && deerVote > lightVote) {
        printf("Leading Candidate is Deer with %d Votes\n", deerVote);
    } else if (lightVote > penVote && lightVote > spoonVote && lightVote > deerVote) {
        printf("Leading Candidate is Light with %d Votes\n", lightVote);
    } else {
        printf("**No one leading**\n");
    }
}

void voteexit()
{

    if ( number == 0)
    {
         printf("**Exit**\n");
        return;
    }


}
int main(){
    while (1)
    {
        printf("1.Cast the vote 2.Find vote count 3. Find leading candidate 4.Exit : ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:

            castvote();
            break;
        case 2:
            votecount();

            break;
        case 3:
            leadingcandid();

            break;
        case 4:
            voteexit();
            return 0;                
        
        default:
            printf("**Error**");
            break;
        }

    }

    return 0;
    
}

//saikat


