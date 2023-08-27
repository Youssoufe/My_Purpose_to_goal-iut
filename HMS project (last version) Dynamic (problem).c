#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


int found;
int ID;
int size=0;
int continue_appointment=0;
int fixed_day_finder=0;
char doctor_na[20]="NULL";
char fixed_day[10]="NULL";
char atomatic[20];
char date1[20]="NULL";
struct ad
{
    char first_name[40],last_name[40];
    char address[30],email[40], gender[10],problem[40];
    char contact[11];
    char age[10];
    char ID_patient[10];
} x[100];

struct doctors
{
    char name[40],Specialty[50];
    char Education[40],Experience[50], Certifications[50],Availability[50];
    char Communication[50];
} y[100];

struct oppintment
{
    char patient_name[40],doctor_name[40],day[40];
    char date[30],time[10];
    char ID_patient[10];
} z[100];



void add();
void list();
void search();
void edit();
void del();


int maxFirstNameWidth = strlen("First Name");
int maxLastNameWidth = strlen("Last Name");
int maxGenderWidth = strlen("Gender");
int maxAgeWidth = strlen("Age");
int maxAddressWidth = strlen("Address");
int maxNumberWidth = strlen("Number");
int maxEmailWidth = strlen("Email");
int maxProblemWidth = strlen("Problem");
int maxIDWidth = strlen("ID");

int maxNameWidth = strlen("Name");
int maxSpecialtyWidth = strlen("Specialty");
int maxEducationWidth = strlen("Education");
int maxExperienceWidth = strlen("Experience");
int maxCertificationsWidth = strlen("Certifications");
int maxAvailabilityWidth = strlen("Availability");
int maxCommunicationWidth = strlen("Communication");

int maxPatientNameWidth = strlen("Patient Name");
int maxDateWidth = strlen("Date");
int maxDayWidth = strlen("Day");
int maxTimeWidth = strlen("Time");
int maxDoctorNameWidth = strlen("Doctor Name");

int main()
{
    printf("\n\n\n\n\n\n\t\t\t\t#########################################\n\t\t\t\t#\t\tWELCOME TO\t\t#\n\t\t\t\t# AL MATRI HOSPITAL MANAGEMENT SYSTEM\t#\n\t\t\t\t#########################################\n\n\n\n\n");
    getch();
    system("cls");
    char k[7],q[7],s;
    int c,num=0;
    int choose;
    do
    {
        system("cls");
        printf("\n\n\t\t----------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t----------------------------------------------------------------------");

        printf("\n\n\n\n\t\t\t\t1. Patient Page\n\n\t\t\t\t2. System Page\n\n\t\t\t\t3. Exit\n\n\n\t\t\t\tNOTE*(Choose from 1 to 3)");


        printf("\n\n\t\t\t\tEnter your choose \n\n\t\t\t\t\tchoose: ");
        scanf("%d",&choose);

        switch(choose)
        {
        case 1:
            system("cls");
            customer();
            break;
        case 2:
            system("cls");

            do
            {
                int c,num=0;
                system("cls");
                printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t    AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
                printf("\n\n\n\t\t\t\tEnter your username and password :\n\n\t\t\t\t\tusername:");
                scanf("%s",k);
                printf("\n\t\t\t\t\tpassword:");
                scanf("%s",q);
                if(((strcmp(k,"s"))||strcmp(q,"s")!=0))
                {
                    printf("\n Your password or username is not valid >> Do you want to try again?[Y/N]");
                    scanf(" %c",&s);
                }
                else
                {
                    printf("\n\t\t\t\t\t.....LOGIN SUCCESSFULLY.....");
                    getch();
                    system("cls");
                    do
                    {
                        system("cls");
                        printf("\n\n\t\t---------------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t---------------------------------------------------------------------------");
                        printf("\n\n\n\n\t\t\t\t1. Add Patient Record\n\n\t\t\t\t2. List Patients Records\n\n\t\t\t\t3. Search Patient Record\n\n\t\t\t\t4. Edit Patient Record\n\n\t\t\t\t5. Delete Patient Record\n\n\t\t\t\t6. Patients Feedback And About Hospital\n\n\t\t\t\t7. Make An Appointment\n\n\t\t\t\t8. List Appointment Record\n\n\t\t\t\t9. Exit\n\n\n\n\t\t\t\tNOTE*[Choose from 1 to 9 ]: ");
                        scanf("%d",&c);
                        switch(c)
                        {
                        case 1:
                            system("cls");
                            add();
                            break;
                        case 2:
                            system("cls");
                            list();
                            break;
                        case 3:
                            system("cls");
                            search();
                            break;
                        case 4:
                            system("cls");
                            edit();
                            break;
                        case 5:
                            system("cls");
                            del();
                            break;
                        case 6:
                            system("cls");
                            show();
                            break;
                        case 7:
                            system("cls");
                            check();
                            break;
                        case 8:
                            system("cls");
                            list_all_appointment();
                            break;
                        case 9:
                            system("cls");
                            printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
                            num=1;
                            break;
                        }
                        if(num==1)
                            break;
                    }
                    while(1);
                }
                if(num==1)
                    break;
            }
            while(s=='Y'||s=='y');
            break;

        case 3:
            system("cls");
            printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
            exit(1);

        }


    }
    while(1);
    getch();
}



void add()
{
    char d;
    int flag=0;
    int large=0,see_id,i=0;
    FILE *fp;
    fp=fopen("project_file.txt","r");
    char A[20], B[20], C[20], D[20], E[20], F[20],G[20],H[20];
    while (fscanf(fp, "%d %15s %15s %15s %15s %15s %15s %15s %15s", &see_id, A, B, C, D, E, F, G, H) == 9)
    {
        if (see_id > large)
        {
            large = see_id;
        }
    }

    ID = large;
    fclose(fp);
    fp=fopen("project_file.txt","a");

    do
    {
        ID++;
        fprintf(fp,"%d ",ID);
        system("cls");
        printf("\n\n\t\t----------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t----------------------------------------------------------------------");
        printf("\n\n\t\t\t################# Add Patient Record #################");
        do
        {
            printf("\n\n\t\t\t\tFirst Name: ");
            scanf("%s",x[size].first_name);
            if(strlen(x[size].first_name)>2&&strlen(x[size].first_name)<20)
            {
                flag=1;
                fprintf(fp,"%s ",x[size].first_name);
            }
            if(flag=1)
                break;
            else
            {
                printf("\n\n\t\t\tWrong entry, The first name must be more than two characters and less than twenty characters");

            }
        }
        while(1);
        do
        {
            printf("\n\n\t\t\t\tLast name: ");
            scanf("%s",x[size].last_name);
            if(strlen(x[size].last_name)>2&&strlen(x[size].last_name)<20)
            {
                flag=2;
                fprintf(fp,"%s ",x[size].last_name);
            }
            if(flag=2)
                break;
            else
            {
                printf("\n\n\t\t\tWrong entry, The last name must be more than two characters and less than twenty characters");

            }
        }
        while(1);
        do
        {
            printf("\n\n\t\t\t\tGender[F/M]: ");
            scanf("%s",x[size].gender);
            if(strcmp(x[size].gender,"m")==0 ||strcmp(x[size].gender,"M")==0 || strcmp(x[size].gender,"f")==0 || strcmp(x[size].gender,"F")==0)
            {
                flag=3;
                fprintf(fp,"%s ",x[size].gender);
            }
            if(flag==3)
            {
                break;
            }
            else
            {
                printf("\n\n\t\t\tGender contains invalid character :(enter either m or M or f or F)");
            }
        }
        while(1);
        printf("\n\n\t\t\t\tAge: ");
        scanf("%s",x[size].age);
        fprintf(fp,"%s ",x[size].age);

        do
        {
            printf("\n\n\t\t\t\tAddress: ");
            fflush(stdin);
            gets(x[size].address);
            fflush(stdin);
            if(strlen(x[size].address)>2&&strlen(x[size].address)<20)
            {
                flag=4;
                fprintf(fp,"%s ",x[size].address);
            }
            if(flag==4)
            {
                break;
            }
            else
            {
                printf("\n\n\t\t\tWrong entry, The address must be more than four characters and less than twenty characters");
            }
        }
        while(1);
        printf("\n\n\t\t\t\tContact no: ");
        scanf("%s",x[size].contact);
        fprintf(fp,"%s ",x[size].contact);

        do
        {
            printf("\n\n\t\t\t\tEmail: ");
            scanf("%s",x[size].email);
            if(strlen(x[size].email)>8&&strlen(x[size].email)<20)
            {
                flag=5;
                fprintf(fp,"%s ",x[size].email);
            }
            if(flag==5)
            {
                break;
            }
            else
            {
                printf("\n\n\t\t\tWrong entry, The email must be more than eigth characters and less than twenty characters");
            }
        }
        while(1);

        do
        {
            printf("\n\n\t\t\t\tProblem: ");
            scanf("%s",x[size].problem);
            if(strlen(x[size].problem)>2&&strlen(x[size].problem)<30)
            {
                flag=6;
                fprintf(fp,"%s \n",x[size].problem);
                fclose(fp);
            }
            if(flag==6)
            {
                break;
            }
            else
            {
                printf("\n\n\t\t\tWrong entry, The problem must be more than three characters and less than thrity characters");
            }
        }
        while(1);

        size++;
        printf("\n\n\t\t\t....Information has been recorded successfully....");
        if(found==-1)
        {
            system("cls");
            printf("\n\n\t\t\t....Information has been recorded successfully....");
            printf("\n\n\t\t\t************ The New ID is: %d *************",ID);
            break;
        }

        printf("\n\t\t\t\tDo you want to add more[Y/N]? ");
        scanf(" %c",&d);

    }
    while(d=='Y'||d=='y');



}


void list()
{
    int i=0,j;


    printf("\n\n\t------------------------------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t############## List Patient Record ##############");
    FILE *fp;
    fp=fopen("project_file.txt","r");
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF)
    {

        if (strlen(x[i].ID_patient) > maxIDWidth)
        {
            maxIDWidth = strlen(x[i].ID_patient);
        }
        if (strlen(x[i].first_name) > maxFirstNameWidth)
        {
            maxFirstNameWidth = strlen(x[i].first_name);
        }
        if (strlen(x[i].last_name) > maxLastNameWidth)
        {
            maxLastNameWidth = strlen(x[i].last_name);
        }
        if (strlen(x[i].gender) > maxGenderWidth)
        {
            maxGenderWidth = strlen(x[i].gender);
        }
        if (strlen(x[i].age) > maxAgeWidth)
        {
            maxAgeWidth = strlen(x[i].age);
        }
        if (strlen(x[i].address) > maxAddressWidth)
        {
            maxAddressWidth = strlen(x[i].address);
        }
        if (strlen(x[i].contact) > maxNumberWidth)
        {
            maxNumberWidth = strlen(x[i].contact);
        }
        if (strlen(x[i].email) > maxEmailWidth)
        {
            maxEmailWidth = strlen(x[i].email);
        }
        if (strlen(x[i].problem) > maxProblemWidth)
        {
            maxProblemWidth = strlen(x[i].problem);
        }
        i++;
        j=i;
    }
    printf("\n\n\n");



    // Print the table headers
    printf("   %-*s  ", maxIDWidth, "ID");
    printf("   %-*s  ", maxFirstNameWidth, "First Name");
    printf("   %-*s  ", maxLastNameWidth, "Last Name");
    printf("   %-*s  ", maxGenderWidth, "Gender");
    printf("   %-*s  ", maxAgeWidth, "Age");
    printf("   %-*s  ", maxAddressWidth, "Address");
    printf("   %-*s  ", maxNumberWidth, "Number");
    printf("   %-*s  ", maxEmailWidth, "Email");
    printf("   %-*s  ", maxProblemWidth, "Problem");
    printf("\n   **************************************************************************************************************");

    printf("\n");

    // Print the table data
    if(i>0)
    {
        for ( i = 0; i < j; i++)
        {
            printf("   %-*s  ", maxIDWidth,x[i].ID_patient );
            printf("   %-*s  ", maxFirstNameWidth, x[i].first_name);
            printf("   %-*s  ", maxLastNameWidth, x[i].last_name);
            printf("   %-*s  ", maxGenderWidth, x[i].gender);
            printf("   %-*s  ", maxAgeWidth, x[i].age);
            printf("   %-*s  ", maxAddressWidth, x[i].address);
            printf("   %-*s  ", maxNumberWidth, x[i].contact);
            printf("   %-*s  ", maxEmailWidth, x[i].email);
            printf("   %-*s  ", maxProblemWidth, x[i].problem);
            printf("\n");
        }
    }
    fclose(fp);

    getch();
}

void  search()
{
    char small[40],l,ch[20],captil[40],r[40];
    int flag,i,j,choice;
    FILE *fp;
    do
    {
        flag=0;
        int convert=0,only_once=0,number_of_lines=0;
        char ID_search[10];
        fp=fopen("project_file.txt","r");
        system("cls");
        printf("\n\n\t---------------------------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t---------------------------------------------------------------------------------------");
        printf("\n\n\t\t      *************** Search Patients Records ***************");
        printf("\n\n\t1.Baised on ID\n\n\t2.Baised on Name\n\n\tEnter your choice: ");
        scanf("%d",&choice);
        if(choice==2)
        {
            printf("\n\n\nEnter patient Name: ");
            scanf("%s",r);
            strcpy(small,r);
            strcpy(captil,r);
            while (captil[convert] != '\0')
            {
                captil[convert] = toupper(captil[convert]);

                convert++;
            }

            convert=0;
            while (small[convert] != '\0')
            {
                small[convert] = tolower(small[convert]);
                convert++;
            }
        }
        if(choice==1)
        {
            printf("\n\n\nEnter patient ID to view Information: ");
            scanf("%s",ID_search);
        }
        i=0;

        while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF)
        {
            if (strlen(x[i].ID_patient) > maxIDWidth)
            {
                maxIDWidth = strlen(x[i].ID_patient);
            }

            if (strlen(x[j].first_name) > maxFirstNameWidth)
            {
                maxFirstNameWidth = strlen(x[j].first_name);
            }
            if (strlen(x[j].last_name) > maxLastNameWidth)
            {
                maxLastNameWidth = strlen(x[j].last_name);
            }
            if (strlen(x[j].gender) > maxGenderWidth)
            {
                maxGenderWidth = strlen(x[j].gender);
            }
            if (strlen(x[j].age) > maxAgeWidth)
            {
                maxAgeWidth = strlen(x[j].age);
            }
            if (strlen(x[j].address) > maxAddressWidth)
            {
                maxAddressWidth = strlen(x[j].address);
            }
            if (strlen(x[j].contact) > maxNumberWidth)
            {
                maxNumberWidth = strlen(x[j].contact);
            }
            if (strlen(x[j].email) > maxEmailWidth)
            {
                maxEmailWidth = strlen(x[j].email);
            }
            if (strlen(x[j].problem) > maxProblemWidth)
            {
                maxProblemWidth = strlen(x[j].problem);
            }
            number_of_lines++;
        }



        fclose(fp);
        fp=fopen("project_file.txt","r");
        i=0;
        while(i<=number_of_lines && choice==2 || choice==1 )
        {
            while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF)
            {
                if(choice==2)
                {
                    if(strcmp(x[i].first_name,small)==0 || strcmp(x[i].first_name,captil)==0)
                    {
                        flag=1;
                        break;

                    }
                }
                if(choice==1)
                {
                    if(strcmp(x[i].ID_patient,ID_search)==0)
                    {
                        flag=1;
                        break;

                    }
                }
                i++;
                j=i;
            }
            if(flag==0)
            {
                printf("\n\t\t\t<<<< Not found patient >>>>");
            }
            else
            {

                if(only_once==0)
                {
                    printf("\n\n\n");

                    // Print the table headers
                    printf("   %-*s  ", maxIDWidth, "ID");
                    printf("   %-*s  ", maxFirstNameWidth, "First Name");
                    printf("   %-*s  ", maxLastNameWidth, "Last Name");
                    printf("   %-*s  ", maxGenderWidth, "Gender");
                    printf("   %-*s  ", maxAgeWidth, "Age");
                    printf("   %-*s  ", maxAddressWidth, "Address");
                    printf("   %-*s  ", maxNumberWidth, "Number");
                    printf("   %-*s  ", maxEmailWidth, "Email");
                    printf("   %-*s  ", maxProblemWidth, "Problem");
                    printf("\n   ***********************************************************************************************************");

                    printf("\n");
                }
                only_once++;

                printf("   %-*s  ", maxIDWidth,x[i].ID_patient );
                printf("   %-*s  ", maxFirstNameWidth, x[i].first_name);
                printf("   %-*s  ", maxLastNameWidth, x[i].last_name);
                printf("   %-*s  ", maxGenderWidth, x[i].gender);
                printf("   %-*s  ", maxAgeWidth, x[i].age);
                printf("   %-*s  ", maxAddressWidth, x[i].address);
                printf("   %-*s  ", maxNumberWidth, x[i].contact);
                printf("   %-*s  ", maxEmailWidth, x[i].email);
                printf("   %-*s  ", maxProblemWidth, x[i].problem);
                printf("\n");
            }
            if(choice==1)
                break;

            i++;
        }
        printf("\n\nDo you want to view more[Y/N]?");
        scanf(" %c",&l);
        fclose(fp);
    }
    while(l=='Y'||l=='y');

}

void edit()
{
    char s[40],q[5],n[5];
    char small[40],captil[40],edit_patient_ID[10];;
    int i,j=0,save=101,flag,convert=0;
    FILE *fp,*temp;

    do
    {

        fp=fopen("project_file.txt","r");
        temp=fopen("temp.txt","a");
        flag=0;
        system("cls");
        printf("\n\n\t\t------------------------------------------------------------------------\n\t\t\t\t\t  AL MATRI HOSPITAL\n\t\t------------------------------------------------------------------------");
        printf("\n\n\t\t\t************** Edit Patients Records **************");
        printf("\n\n\n\t\tEnter patient ID: ");
        scanf("%s",edit_patient_ID);
        printf("\n\n\t\tEnter the first name of the patient: ");
        scanf("%s",s);


        strcpy(small,s);
        strcpy(captil,s);

        while (captil[convert] != '\0')
        {
            captil[convert] = toupper(captil[convert]);

            convert++;
        }

        convert=0;
        while (small[convert] != '\0')
        {
            small[convert] = tolower(small[convert]);
            convert++;
        }


        for(i=0; fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF; i++)
        {
            if(strcmp(captil,x[i].first_name)==0 || strcmp(small,x[i].first_name)==0 && strcmp(edit_patient_ID,x[i].ID_patient)==0)
            {
                flag=1;
                j=i;
                save=i;
            }

            if(save!=i)
            {
                fprintf(temp,"%s ",x[i].ID_patient);
                fprintf(temp,"%s ",x[i].first_name);
                fprintf(temp,"%s ",x[i].last_name);
                fprintf(temp,"%s ",x[i].gender);
                fprintf(temp,"%s ",x[i].age);
                fprintf(temp,"%s ",x[i].address);
                fprintf(temp,"%s ",x[i].contact);
                fprintf(temp,"%s ",x[i].email);
                fprintf(temp,"%s \n",x[i].problem);
            }



        }

        if(flag==0)
        {
            printf("\n\t\t\t\t<<< Not found >>>");
        }
        else
        {
            do
            {
                printf("\n\n\t\t\t***** Existing record *****\n\t");
                int maxIDWidth = strlen("ID");
                int maxFirstNameWidth = strlen("First Name");
                int maxLastNameWidth = strlen("Last Name");
                int maxGenderWidth = strlen("Gender");
                int maxAgeWidth = strlen("Age");
                int maxAddressWidth = strlen("Address");
                int maxNumberWidth = strlen("Number");
                int maxEmailWidth = strlen("Email");
                int maxProblemWidth = strlen("Problem");


                if (strlen(x[j].ID_patient) > maxIDWidth)
                {
                    maxIDWidth = strlen(x[j].ID_patient);
                }

                if (strlen(x[j].first_name) > maxFirstNameWidth)
                {
                    maxFirstNameWidth = strlen(x[j].first_name);
                }
                if (strlen(x[j].last_name) > maxLastNameWidth)
                {
                    maxLastNameWidth = strlen(x[j].last_name);
                }
                if (strlen(x[j].gender) > maxGenderWidth)
                {
                    maxGenderWidth = strlen(x[j].gender);
                }
                if (strlen(x[j].age) > maxAgeWidth)
                {
                    maxAgeWidth = strlen(x[j].age);
                }
                if (strlen(x[j].address) > maxAddressWidth)
                {
                    maxAddressWidth = strlen(x[j].address);
                }
                if (strlen(x[j].contact) > maxNumberWidth)
                {
                    maxNumberWidth = strlen(x[j].contact);
                }
                if (strlen(x[j].email) > maxEmailWidth)
                {
                    maxEmailWidth = strlen(x[j].email);
                }
                if (strlen(x[j].problem) > maxProblemWidth)
                {
                    maxProblemWidth = strlen(x[j].problem);
                }

                printf("\n\n\n");

                // Print the table headers
                printf("   %-*s  ", maxIDWidth, "ID");
                printf("   %-*s  ", maxFirstNameWidth, "First Name");
                printf("   %-*s  ", maxLastNameWidth, "Last Name");
                printf("   %-*s  ", maxGenderWidth, "Gender");
                printf("   %-*s  ", maxAgeWidth, "Age");
                printf("   %-*s  ", maxAddressWidth, "Address");
                printf("   %-*s  ", maxNumberWidth, "Number");
                printf("   %-*s  ", maxEmailWidth, "Email");
                printf("   %-*s  ", maxProblemWidth, "Problem");
                printf("\n  ***********************************************************************************************************");

                printf("\n");
                printf("   %-*s  ", maxIDWidth,x[j].ID_patient );
                printf("   %-*s  ", maxFirstNameWidth, x[j].first_name);
                printf("   %-*s  ", maxLastNameWidth, x[j].last_name);
                printf("   %-*s  ", maxGenderWidth, x[j].gender);
                printf("   %-*s  ", maxAgeWidth, x[j].age);
                printf("   %-*s  ", maxAddressWidth, x[j].address);
                printf("   %-*s  ", maxNumberWidth, x[j].contact);
                printf("   %-*s  ", maxEmailWidth, x[j].email);
                printf("   %-*s  ", maxProblemWidth, x[j].problem);
                printf("\n");

                fprintf(temp,"%s ",x[j].ID_patient);
                do
                {
                    printf("\n\n\t\t\t\tFirst Name: ");
                    scanf("%s",x[j].first_name);
                    if(strlen(x[j].first_name)>2&&strlen(x[j].first_name)<20)
                    {
                        flag=1;
                        fprintf(temp,"%s ",x[j].first_name);
                    }
                    if(flag==1)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n\n\t\t\tWrong entry, The first name must be more than two characters and less than twenty characters");

                    }

                }
                while(1);
                do
                {
                    printf("\n\n\t\t\t\tLast name: ");
                    scanf("%s",x[j].last_name);
                    if(strlen(x[j].last_name)>2&&strlen(x[j].last_name)<20)
                    {
                        flag=2;
                        fprintf(temp,"%s ",x[j].last_name);
                    }
                    if(flag=2)
                        break;
                    else
                    {
                        printf("\n\n\t\t\tWrong entry, The last name must be more than two characters and less than twenty characters");

                    }
                }
                while(1);
                do
                {
                    printf("\n\n\t\t\t\tGender[F/M]: ");
                    scanf("%s",x[j].gender);
                    if(strcmp(x[j].gender,"m")==0 ||strcmp(x[j].gender,"M")==0 || strcmp(x[j].gender,"f")==0 || strcmp(x[j].gender,"F")==0)
                    {
                        flag=3;
                        fprintf(temp,"%s ",x[j].gender);
                    }
                    if(flag==3)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n\n\t\t\tGender contains invalid character :(enter either m or M or f or F)");
                    }
                }
                while(1);
                printf("\n\n\t\t\t\tAge: ");
                scanf("%s",x[j].age);
                fprintf(temp,"%s ",x[j].age);
                do
                {
                    printf("\n\n\t\t\t\tAddress: ");
                    scanf("%s",x[j].address);
                    if(strlen(x[j].address)>4&&strlen(x[j].address)<20)
                    {
                        flag=4;
                        fprintf(temp,"%s ",x[j].address);
                    }
                    if(flag==4)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n\n\t\t\tWrong entry, The address must be more than four characters and less than twenty characters");
                    }
                }
                while(1);
                printf("\n\n\t\t\t\tContact no: ");
                scanf("%s",x[j].contact);
                fprintf(temp,"%s ",x[j].contact);

                do
                {
                    printf("\n\n\t\t\t\tEmail: ");
                    scanf("%s",x[j].email);
                    if(strlen(x[j].email)>8&&strlen(x[j].email)<20)
                    {
                        flag=5;
                        fprintf(temp,"%s ",x[j].email);
                    }
                    if(flag==5)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n\n\t\t\tWrong entry, The email must be more than eigth characters and less than twenty characters");
                    }
                }
                while(1);

                do
                {
                    printf("\n\n\t\t\t\tProblem: ");
                    scanf("%s",x[j].problem);
                    if(strlen(x[j].problem)>2&&strlen(x[j].problem)<30)
                    {
                        flag=6;
                        fprintf(temp,"%s \n",x[j].problem);
                        fclose(temp);
                        fclose(fp);
                    }
                    if(flag==6)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n\n\t\t\tWrong entry, The problem must be more than three characters and less than thrity characters");
                    }
                }
                while(1);

                printf("\nPress U for ensuring updating operation: ");
                scanf("%s",q);
            }
            while(strcmp(q,"U")!=0&& strcmp(q,"u")!=0);

        }
        if(strcmp(q,"U")==0 || strcmp(q,"u")==0)
        {
            printf("\n\t\t\t\t\tPatient record updated successfully...");
        }
        remove("project_file.txt");
        rename("temp.txt","project_file.txt");

        printf("\n\n\tDo you want to update more[Y/N]?");
        scanf("%s",n);
    }
    while(strcmp(n,"y")==0 || strcmp(n,"Y")==0);
}

void del()
{

    FILE *fp,*temp;
    int times=0;
    char small[40],captil[40],delete_patient_ID[10];
    int i,flag=0,save,convert=0;
    char a[40],n;

    do
    {
        flag=0;
        save=101;
        fp=fopen("project_file.txt","r");
        temp=fopen("temp.txt","a");
        system("cls");
        printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
        printf("\n\n\t\t\t\t############### Delete Patient Record ###############");
        printf("\n\n\t\tEnter patient ID: ");
        scanf("%s",delete_patient_ID);
        printf("\n\n\t\tEnter patient first name: ");
        scanf("%s",a);

        strcpy(small,a);
        strcpy(captil,a);

        while (captil[convert] != '\0')
        {
            captil[convert] = toupper(captil[convert]);
            // printf("Uppercase String: %s\n", str);
            convert++;
        }

        convert=0;
        while (small[convert] != '\0')
        {
            small[convert] = tolower(small[convert]);
            convert++;
        }



        for(i=0; fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF; i++)
        {
            if(strcmp(x[i].first_name,small)==0 || strcmp(x[i].first_name,captil)==0 && strcmp(x[i].ID_patient,delete_patient_ID)==0)
            {
                flag=1;
                continue;
            }
            fprintf(temp,"%s ",x[i].ID_patient);
            fprintf(temp,"%s ",x[i].first_name);
            fprintf(temp,"%s ",x[i].last_name);
            fprintf(temp,"%s ",x[i].gender);
            fprintf(temp,"%s ",x[i].age);
            fprintf(temp,"%s ",x[i].address);
            fprintf(temp,"%s ",x[i].contact);
            fprintf(temp,"%s ",x[i].email);
            fprintf(temp,"%s \n",x[i].problem);
        }

        if(flag==1)
            printf("\n\n\t\t\t<<<<< Deleting is Done >>>>>\n\n");

        else
            printf("\n\n\t\t\t<<<<< Not found name to delete >>>>>\n\n");
        printf("Do you want to try again[Y/N]?");
        scanf(" %c",&n);
        fclose(fp);
        fclose(temp);
        remove("project_file.txt");
        rename("temp.txt","project_file.txt");

    }
    while(n=='Y'||n=='y');


}




void customer(void)
{
    int n,c=0;
    FILE *fp;
    char str[300],line[100];
    do
    {
        system("cls");
        printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
        printf("\n\n\n\n\t\t\t\t1. About Hospital\n\n\t\t\t\t2. Doctors Information\n\n\t\t\t\t3. Write A Complain\n\n\t\t\t\t4. Exit\n\n\t\t\t\NOTE*(Choose from 1 to 4)");

        printf("\n\n\t\tEnter your choose: ");
        scanf("%d",&n);

        switch(n)
        {
        case 1:

            fp=fopen("About Hospital.txt","r");
            system("cls");
            printf("\n\n\t******** Hospital Information Page ********\n\n");

            while (fgets(line, sizeof(line), fp) != NULL)
            {
                printf("\t%s", line);
            }
            fclose(fp);
            break;

        case 2:
            fp=fopen("Doctors Information.txt","r");
            int i=0,j;
            system("cls");
            printf("\n\n\t-----------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\t    AL MATRI HOSPITAL\n\t-----------------------------------------------------------------------------------------------------------");
            printf("\n\n\t\t####################### list Doctors Information #########################");
            while(fscanf(fp,"%s %s %s %s %s %s %s",y[i].name,y[i].Specialty,y[i].Education,y[i].Experience,y[i].Certifications,y[i].Availability,y[i].Communication)!=EOF)
            {

                if (strlen(y[i].name) > maxNameWidth)
                {
                    maxNameWidth = strlen(y[i].name);
                }
                if (strlen(y[i].Specialty) > maxSpecialtyWidth)
                {
                    maxSpecialtyWidth = strlen(y[i].Specialty);
                }
                if (strlen(y[i].Education) > maxEducationWidth)
                {
                    maxEducationWidth = strlen(y[i].Education);
                }
                if (strlen(y[i].Experience) > maxExperienceWidth)
                {
                    maxExperienceWidth = strlen(y[i].Experience);
                }
                if (strlen(y[i].Certifications) > maxCertificationsWidth)
                {
                    maxCertificationsWidth = strlen(y[i].Certifications);
                }
                if (strlen(y[i].Availability) > maxAvailabilityWidth)
                {
                    maxAvailabilityWidth = strlen(y[i].Availability);
                }
                if (strlen(y[i].Communication) > maxCommunicationWidth)
                {
                    maxCommunicationWidth = strlen(y[i].Communication);
                }

                i++;
                j=i;
            }
            printf("\n\n\n");

            // Print the table headers
            printf("%-*s  ",maxNameWidth, "Name");
            printf("%-*s  ", maxSpecialtyWidth, "Specialty");
            printf("%-*s  ", maxEducationWidth, "Education");
            printf("%-*s  ", maxExperienceWidth, "Experience");
            printf("%-*s  ", maxCertificationsWidth, "Certifications");
            printf("%-*s  ", maxAvailabilityWidth, "Availability");
            printf("%-*s  ", maxCommunicationWidth, "Communication");
            printf("\n************************************************************************************************************************************************************");

            printf("\n");

            // Print the table data
            if(i>0)
            {
                for ( i = 0; i < j; i++)
                {
                    printf("%-*s  ", maxNameWidth, y[i].name);
                    printf("%-*s  ", maxSpecialtyWidth, y[i].Specialty);
                    printf("%-*s  ", maxEducationWidth, y[i].Education);
                    printf("%-*s  ", maxExperienceWidth, y[i].Experience);
                    printf("%-*s  ", maxCertificationsWidth, y[i].Certifications);
                    printf("%-*s  ", maxAvailabilityWidth, y[i].Availability);
                    printf("%-*s  ", maxCommunicationWidth, y[i].Communication);
                    printf("\n");
                }
            }

            fclose(fp);
            break;

        case 3:
            fp=fopen("Complain.txt","a");
            fflush(stdin);
            system("cls");
            printf("\n\n\t******** Patient Feedback Page ********\n\n\t");
            gets(str);
            fprintf(fp,"%s \n",str);
            fclose(fp);
        case 4:
            break;

        }
        if(n==4)
            break;
        printf("\n\n\t1.Back To Main Page\n\n\t2.Back To Previous Page\n\n\t: ");
        scanf("%d",&c);

    }
    while(c==2);

}


void show(void)
{

    int n,c,count=0;
    FILE *fp;
    char d,line[100];
    int flag=0;
    char str[200];
    do
    {
        system("cls");
        printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
        printf("\n\n\n\n\t\t\t\t1. Write About Hospital\n\n\t\t\t\t2. Write Doctors Information\n\n\t\t\t\t3. Read A Complain\n\n\t\t\t\t4. Exit\n\n\t\t\t\tNOTE*(Choose from 1 to 4)");

        printf("\n\n\t\tEnter your choose: ");
        scanf("%d",&n);
        printf("\n\n");

        switch(n)
        {
        case 1:

            fp=fopen("About Hospital.txt","a");
            fflush(stdin);
            system("cls");
            printf("\n\n\t******** Staff Hospital Page Information ********\n\n\t");
            gets(str);
            fprintf(fp,"%s \n",str);

            fclose(fp);
            break;

        case 2:
            fp=fopen("Doctors Information.txt","a");

            do
            {
                system("cls");
                printf("\n\n\t\t----------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t----------------------------------------------------------------------");
                printf("\n\n\t\t\t\t########## Add Doctors Information ##########");

                printf("\n\n\t\t\t\tName: ");
                fflush(stdin);
                gets(y[count].name);
                fprintf(fp,"%s ",y[count].name);

                printf("\n\n\t\t\t\tSpecialty: ");
                gets(y[count].Specialty);
                fprintf(fp,"%s ",y[count].Specialty);



                printf("\n\n\t\t\t\tEducation: ");
                gets(y[count].Education);
                fprintf(fp,"%s ",y[count].Education);

                printf("\n\n\t\t\t\tExperience: ");
                gets(y[count].Experience);
                fprintf(fp,"%s ",y[count].Experience);

                printf("\n\n\t\t\t\tCertifications: ");
                gets(y[count].Certifications);
                fprintf(fp,"%s ",y[count].Certifications);

                printf("\n\n\t\t\t\tAvailability: ");
                gets(y[count].Availability);
                fprintf(fp,"%s ",y[count].Availability);

                printf("\n\n\t\t\t\tCommunication: ");
                gets(y[count].Communication);
                fprintf(fp,"%s \n",y[count].Communication);


                count++;
                printf("\n\n\t\t\t....Information has been recorded successfully....");
                printf("\n\t\t\t\tDo you want to add more[Y/N]? ");
                scanf(" %c",&d);

            }
            while(d=='Y'||d=='y');

            fclose(fp);
            break;

        case 3:
            fp=fopen("Complain.txt","r");
            system("cls");
            printf("\n\n\t******** Hospital Feedback Page ********\n\n");
            while (fgets(line, sizeof(line), fp) != NULL)
            {
                printf("\t%s", line);
            }
            fclose(fp);
        case 4:
            break;

        }
        if(n==4)
            break;
        printf("\n\n\t1.Back To Main Page\n\n\t2.Back To Previous Page\n\n\t: ");
        scanf("%d",&c);

    }
    while(c==2);



}


int search_2(void)
{

    char l,ch[20],r[40];
    int flag,i,j,choice;
    FILE *fp;

    flag=0;
    int convert=0;
    char ID_search[10];
    fp=fopen("project_file.txt","r");
    system("cls");
    printf("\n\n\t\t\t-----------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t\t\t-----------------------------------------------------------------");
    printf("\n\n\t1.Enter ID: ");

    scanf("%s",ID_search);

    i=0;

    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",x[i].ID_patient,x[i].first_name,x[i].last_name,x[i].gender,x[i].age,x[i].address,x[i].contact,x[i].email,x[i].problem)!=EOF)
    {


        if(strcmp(x[i].ID_patient,ID_search)==0)
        {
            flag=1;
            ID=atoi(ID_search);
            strcpy(atomatic,x[i].first_name);
            break;

        }
    }


    fclose(fp);
    return flag;

}


void check()
{

    found=0;
    found = search_2();
    if(found==1)
    {
        make_appointment();
    }
    if(found==0)
    {
        found=-1;
        printf("\n\n\t\t***ID is not found***");
        getch();
        add();
        getch();
        system("cls");
        check();
    }


}

void make_appointment(void)
{

    char d;
    FILE *fp;

    fp=fopen("appointment_file.txt","a");


    if(continue_appointment==0)
    {
        printf("\n\n\tName of the doctor: ");
        scanf("%s",doctor_na);
    }
    printf("\n\n\tDate of reservation: ");
    scanf("%s",date1);
    strcpy(z[size].date,date1);


    list_appointment_reservation(doctor_na,date1);
    printf("\n\n\t\t\t\t########## Add AN Appointmet Record ##########");
    printf("\n\n\t1. Continue\n\t2. See Another Date\n\t3. Cancel\n\n\tEnter Your Choose: ");
    scanf("%d",&continue_appointment);
    if(continue_appointment==1)
    {
        strcpy(z[size].date,date1);
        fprintf(fp,"%d ",ID);
        fprintf(fp,"%s ",atomatic);
        fprintf(fp,"%s ",doctor_na);

        printf("\n\n\t\tTime: ");
        scanf("%s",z[size].time);
        fprintf(fp,"%s ",z[size].time);

        strcpy(z[size].day,fixed_day);
        if(fixed_day_finder==0)
        {
            printf("\n\n\t\tDay: ");
            scanf("%s",z[size].day);

        }
        fprintf(fp,"%s ",z[size].day);
        fixed_day[10]="NULL";
        fixed_day_finder=0;

        fprintf(fp,"%s \n",z[size].date);
        date1[20]="NULL";
    }
    if(continue_appointment==2)
    {
        fixed_day_finder=0;
        system("cls");
        make_appointment();

    }
    if(continue_appointment==3)
    {
    }
    continue_appointment=0;
    fclose(fp);

}

void list_appointment_reservation(const char *str,const char *str1)
{
    FILE*fp;

    int j,i=0,flag=0;
    int count_number_of_lines=0;
    printf("\n\n\n");
    system("cls");




    fp=fopen("appointment_file.txt","r");

    printf("\n\n\t%s\t %s\t\t %s\t %s\t\n","Doctor name","Time","Day","Date");
    printf("\t-------------------------------------------------------");


    while(fscanf(fp,"%s %s %s %s %s %s",z[i].ID_patient,z[i].patient_name,z[i].doctor_name,z[i].time,z[i].day,z[i].date)!=EOF)
    {

        if(strcmp(z[i].doctor_name,str)==0 && strcmp(z[i].date,str1)==0 )
        {

            printf("\n\t%s\t\t %s\t %s\t %s\t\n",z[i].doctor_name,z[i].time,z[i].day,z[i].date);
            strcpy(fixed_day,z[i].day);
            if(strlen(fixed_day)==3)
            {
                fixed_day_finder=1;
            }
        }

        i++;
    }


    fclose(fp);


}

void list_all_appointment()
{

    int i=0,j;
    printf("\n\n\t---------------------------------------------------------------------------------------\n\t\t\t\t\t AL MATRI HOSPITAL\n\t---------------------------------------------------------------------------------------");
    printf("\n\n\t\t!!!!!!!!!!!!!!!!!!! list Appointment Record !!!!!!!!!!!!!!!!!!");

    FILE*fp;
    fp=fopen("appointment_file.txt","r");


    while(fscanf(fp,"%s %s %s %s %s %s",z[i].ID_patient,z[i].patient_name,z[i].doctor_name,z[i].time,z[i].day,z[i].date)!=EOF)
    {

        if (strlen(z[i].ID_patient) > maxIDWidth)
        {
            maxIDWidth = strlen(z[i].ID_patient);
        }
        if (strlen(z[i].patient_name) >maxPatientNameWidth)
        {
            maxPatientNameWidth = strlen(z[i].patient_name);
        }
        if (strlen(z[i].doctor_name) > maxDoctorNameWidth)
        {
            maxDoctorNameWidth = strlen(z[i].doctor_name);
        }
        if (strlen(z[i].time) > maxTimeWidth)
        {
            maxTimeWidth = strlen(z[i].time);
        }
        if (strlen(z[i].day) > maxDayWidth)
        {
            maxDayWidth = strlen(z[i].day);
        }
        if (strlen(z[i].date) > maxDateWidth)
        {
            maxDateWidth = strlen(z[i].date);
        }

        i++;
        j=i;
    }
    printf("\n\n\n");
    // Print the table headers
    printf("%-*s  ", maxIDWidth, "ID");
    printf("%-*s  ", maxPatientNameWidth, "Patient Name");
    printf("%-*s  ", maxDoctorNameWidth, "Doctor Name");
    printf("%-*s  ", maxTimeWidth, "Time");
    printf("%-*s  ", maxDayWidth, "Day");
    printf("%-*s  ", maxDateWidth, "Date");
    printf("\n**************************************************************************");

    printf("\n");

    // Print the table data
    if(i>0)
    {
        for ( i = 0; i < j; i++)
        {
            printf("%-*s  ", maxIDWidth,z[i].ID_patient );
            printf("%-*s  ", maxPatientNameWidth, z[i].patient_name);
            printf("%-*s  ", maxDoctorNameWidth, z[i].doctor_name);
            printf("%-*s  ", maxTimeWidth, z[i].time);
            printf("%-*s  ", maxDayWidth, z[i].day);
            printf("%-*s  ", maxDateWidth, z[i].date);
            printf("\n");
        }
    }

    fclose(fp);


    getch();
}



