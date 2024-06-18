#include<stdio.h>
#include<string.h>
int option = 0 ;
int penVote = 0 , spoonVote = 0, deerVote = 0, lightVote = 0;
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

void savevote()
{
    FILE *file = fopen("votes.txt","w");
    if(file==NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    fprintf(file, "Pen: %d\n", penVote);
    fprintf(file, "Spoon: %d\n", spoonVote);
    fprintf(file, "Deer: %d\n", deerVote);
    fprintf(file, "Light: %d\n", lightVote);
    fprintf(file, "____________");
    fclose(file);
    printf("Vote saved\n");
}

void loadvotes() {
    FILE *file = fopen("votes.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    fscanf(file, "Pen: %d\n", &penVote);
    fscanf(file, "Spoon: %d\n", &spoonVote);
    fscanf(file, "Deer: %d\n", &deerVote);
    fscanf(file, "Light: %d\n", &lightVote);
    fclose(file);
    printf("Votes loaded from votes.txt\n");
}

void deletevotes() {
    if (remove("votes.txt") == 0) {
        printf("Main vote list deleted successfully.\n");
    } else {
        printf("Error deleting votes.txt.\n");
    }
    penVote = 0;
    spoonVote = 0;
    deerVote = 0;
    lightVote = 0;
    printf("All vote counts reset.\n");
}

void securitykey()
{
    long long securitykey =29112003;
    long long key;
    printf("Enter the security key: ");
    scanf("%d", &key);
    if (securitykey==key) {
        deletevotes();
    } else {
        printf("Invalid Key\n");
    }
}

void voteexit()
{
    savevote();
    printf("**Exit**\n");
}
int main(){
    loadvotes();
    while (1)
    {
        printf("1.Cast the vote \n2.Find vote count \n3.Find leading candidate \n4.Delete the main file\n5.Exit\n");
        printf("Your Option:");
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
        {
            securitykey();
            break;
        }
        case 5:
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


