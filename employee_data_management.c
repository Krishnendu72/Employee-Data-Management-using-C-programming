#include<stdio.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                     
#include<string.h>                                                                                                                                                     
void sort();//the function to sort the file based on employees ID  given                                                                                               
void delete(); //to delete a certain employee details based on ID                                                                                                      
void insert();//to insert more employees' details to the file                                                                                                          
void read();//to read the file                                                                                                                                         
void write();//to write in the file                                                                                                                                    
void list();//to list all employees' details by a particular searching element                                                                                         
void edit();//to modify the details of the particular employee                                                                                                         
struct emp                                                                                                                                                             
{                                                                                                                                                                      
        int no,age,salary;                                                                                                                                             
        char details[2][20];                                                                                                                                           
}employees[50];                                                                                                                                                        
FILE *fp;                                                                                                                                                              
char s[100][200],word[200];                                                                                                                                            
void main()                                                                                                                                                            
{                                                                                                                                                                      
        int op;                                                                                                                                                        
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n\t\t
\t\t\t\tWELCOME TO EMPOLYEE MANAGEMENT SYSTEM\n");                                                                                                                     
        printf("\t\t\t\t\t----------------------------------------------------\n");                                                                                    
        while(1){                                                                                                                                                      
        printf("\n\tSERVICES OFFERED\n-----------------------------\n");                                                                                               
        printf("1.EMPLOYEES ENTERING\n2.EMPLOYEES DISPLAYING\n3.EMPLOYEES DELETING\n4.EMPLOYEES INSERTING\n5.EMPLOYEES LISTING\n6.EMPLOYEES EDITING \n7.EMPLOYEES SORTI
NG\n8.EXIT\n");                                                                                                                                                        
        printf("\nCHOOSE THE OPTION PLEASE\t: ");                                                                                                                      
        scanf("%d",&op);                                                                                                                                               
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n"); 
        switch(op)                                                                                                                                                     
        {                                                                                                                                                              
                case 1:                                                                                                                                                
                        write();                                                                                                                                       
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 2:                                                                                                                                                
                        read();                                                                                                                                        
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 3:
                        delete();                                                                                                                                      
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 4:                                                                                                                                                
                        insert();                                                                                                                                      
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 5:                                                                                                                                                
                        list();                                                                                                                                        
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 6:                                                                                                                                                
                        edit();                                                                                                                                        
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 7:                                                                                                                                                
                        sort();                                                                                                                                        
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        break;                                                                                                                                         
                case 8:                                                                                                                                                
                        printf("\t\t\t\t\t\t\tTHANKYOU FOR VISITING!!!");                                                                                              
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                        exit(0);                                                                                                                                       
                default:                                                                                                                                               
                        printf("\nERROR IN CHOOSING OPTION");                                                                                                          
                        printf("\n-------------------------------------------------------------------------------------------------------------------------------------
----------\n");                                                                                                                                                        
                }                                                                                                                                                      
        }                                                                                                                                                              
}                                                                                                                                                                      
void sort()                                                                                                                                                            
{                                                                                                                                                                      
        int n,i,j;                                                                                                                                                     
        fp=fopen("employees.txt","r");//opening the file in read-only mode                                                                                             
        for(i=0;fgets(word,200,fp)!=NULL;i++)                                                                                                                          
        {                                                                                                                                                              
                strcpy(s[i],word);//getting each line and storing it in a 2D array of characters                                                                       
        }                                                                                                                                                              
        fclose(fp);//closing the file                                                                                                                                  
        char temp[200];                                                                                                                                                
        n=i;                                                                                                                                                           
        for(i=2;i<n;i++)//employees no added by two because of first two lines                                                                                         
        {                                                                                                                                                              
                for(j=i+1;j<n;j++)                                                                                                                                     
                {                                                                                                                                                      
                        if(strcmp(s[i],s[j])>0)//comparing strings and ordering as the first few characters are ID                                                     
                        {                                                                                                                                              
                                strcpy(temp,s[i]);                                                                                                                     
                                strcpy(s[i],s[j]);                                                                                                                     
                                strcpy(s[j],temp);                                                                                                                     
                        }                                                                                                                                              
                }                                                                                                                                                      
        }                                                                                                                                                              
        fp=fopen("employees.txt","w");//opening in write-only mode and writing into the file                                                                           
        for(i=0;i<n;i++)                                                                                                                                               
        {                                                                                                                                                              
                fprintf(fp,"%s",s[i]);                                                                                                                                 
        }                                                                                                                                                              
        if(s[0]!=NULL)                                                                                                                                                 
                printf("\nSORTING DONE SUCCESSFULLY\n");                                                                                                               
        else                                                                                                                                                           
                printf("\nERROR OCCURRED\n");                                                                                                                          
        fclose(fp);//closing the file                                                                                                                                  
                                                                                                                                                                       
}                                                                                                                                                                      
void write()                                                                                                                                                           
{                                                                                                                                                                      
        int i=0,nofemployees;                                                                                                                                          
        char bin;//character bin to get \n character                                                                                                                   
        printf("\nENTER THE NO OF ENTRIES\t: ");                                                                                                                       
        scanf("%d",&nofemployees);                                                                                                                                     
        getchar();                                                                                                                                                     
        while(i<nofemployees)                                                                                                                                          
        {                                                                                                                                                              
                printf("\nENTER %d EMPLOYEE NAME: ",i+1);                                                                                                              
                scanf("%[^\n]s",employees[i].details[0]);                                                                                                              
                printf("\nENTER %d EMPLOYEE ID: ",i+1);                                                                                                                
                scanf("%d",&employees[i].no);                                                                                                                          
                printf("\nENTER %d EMPLOYEE AGE: ",i+1);                                                                                                               
                scanf("%d",&employees[i].age);                                                                                                                         
                printf("\nENTER %d EMPLOYEE SALARY: ",i+1);                                                                                                            
                scanf("%d%c",&employees[i].salary,&bin);                                                                                                               
                printf("\nENTER THE DESIGNATION: ");                                                                                                                   
                scanf("%[^\n]s",employees[i].details[1]);                                                                                                              
                getchar();                                                                                                                                             
                printf("\n");                                                                                                                                          
                i++;
        }                                                                                                                                                              
        fp=fopen("employees.txt","w");//writing into the file                                                                                                          
        fprintf(fp,"EMPLOYEE ID                    NAME                    AGE                    PROFESSION                    SALARY    \n");                        
        fprintf(fp,"-----------------------------------------------------------------------------------------------------------------------------------------------\n")
;                                                                                                                                                                      
        for(int i=0;i<nofemployees;i++)                                                                                                                                
                fprintf(fp,"%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i].salary);           
        if(fp!=NULL)                                                                                                                                                   
                printf("\nDETAILS HAVE WRITTEN SUCCESSFULLY\n");                                                                                                       
        else                                                                                                                                                           
                printf("\nERROR OCCURRED\n");                                                                                                                          
        fclose(fp);                                                                                                                                                    
}                                                                                                                                                                      
void read()                                                                                                                                                            
{                                                                                                                                                                      
        fp=fopen("employees.txt","r");                                                                                                                                 
        char ch;                                                                                                                                                       
        ch=fgetc(fp);//reading by character by character                                                                                                               
        while(ch!=EOF)                                                                                                                                                 
        {                                                                                                                                                              
                putchar(ch);                                                                                                                                           
                ch=fgetc(fp);                                                                                                                                          
        }                                                                                                                                                              
        fclose(fp);                                                                                                                                                    
}                                                                                                                                                                      
void insert()                                                                                                                                                          
{                                                                                                                                                                      
        int n,i=0;                                                                                                                                                     
        char bin;                                                                                                                                                      
        struct emp employee[10];                                                                                                                                       
        printf("\nENTER THE NO OF ENTRIES\t: ");                                                                                                                       
        scanf("%d",&n);                                                                                                                                                
        getchar();                                                                                                                                                     
        fp=fopen("employees.txt","a");//inserting by appending to the file                                                                                             
        while(i<n)                                                                                                                                                     
        {                                                                                                                                                              
                printf("\nENTER %d EMPLOYEE NAME: ",i+1);                                                                                                              
                scanf("%[^\n]s",employee[i].details[0]);                                                                                                               
                printf("\nENTER %d EMPLOYEE ID: ",i+1);                                                                                                                
                scanf("%d",&employee[i].no);                                                                                                                           
                printf("\nENTER %d EMPLOYEE AGE: ",i+1);                                                                                                               
                scanf("%d",&employee[i].age);                                                                                                                          
                printf("\nENTER %d EMPLOYEE SALARY: ",i+1);                                                                                                            
                scanf("%d%c",&employee[i].salary,&bin);                                                                                                                
                printf("\nENTER THE DESIGNATION: ");                                                                                                                   
                scanf("%[^\n]s",employee[i].details[1]);                                                                                                               
                getchar();                                                                                                                                             
                printf("\n");                                                                                                                                          
                fprintf(fp,"%-31d%-24s%-23d%-30s%d\n",employee[i].no,employee[i].details[0],employee[i].age,employee[i].details[1],employee[i].salary);                
                i++;                                                                                                                                                   
        }                                                                                                                                                              
        if(fp!=NULL)                                                                                                                                                   
                printf("\nINSERTION DONE SUCCESSFULLY\n");                                                                                                             
        fclose(fp);                                                                                                                                                    
}                                                                                                                                                                      
void edit()                                                                                                                                                            
{                                                                                                                                                                      
        int n,i,id,flag=1,op,k=2;                                                                                                                                      
        char bin;                                                                                                                                                      
                                                                                                                                                                       
        fp=fopen("employees.txt","r");                                                                                                                                 
        for(i=0;i<2;i++)                                                                                                                                               
        {                                                                                                                                                              
                fgets(s[i],200,fp);//getting first two lines as its not employees' informations                                                                        
        }                                                                                                                                                              
        while(fscanf(fp,"%d %s %d %s %d",&employees[n].no,employees[n].details[0],&employees[n].age,employees[n].details[1],&employees[n].salary)==5)                  
        {                                                                                                                                                              
                n++;                                                                                                                                                   
        }                                                                                                                                                              
        fclose(fp);                                                                                                                                                    
        printf("\nENTER THE ID TO EDIT:");                                                                                                                             
        scanf("%d",&id);                                                                                                                                               
        for(i=0;i<n;i++)                                                                                                                                               
        {                                                                                                                                                              
                if(id==employees[i].no)//finding if the id matches                                                                                                     
                {                                                                                                                                                      
                        flag=0;                                                                                                                                        
                        printf("\nENTER WHICH ONE\n1.ID\n2.NAME\n3.DESIGNATION\n4.AGE\n5.SALARY\n==");                                                                 
                        scanf("%d",&op);                                                                                                                               
                        getchar();                                                                                                                                     
                        printf("\nENTER THE CORRECT ONE:");                                                                                                            
                        switch(op)                                                                                                                                     
                        {                                                                                                                                              
                                case 1:                                                                                                                                
                                        scanf("%d%c",&employees[i].no,&bin);                                                                                           
                                        break;                                                                                                                         
                                case 2:                                                                                                                                
                                        scanf("%[^\n]",employees[i].details[0]);                                                                                       
                                        getchar();                                                                                                                     
                                        break;                                                                                                                         
                                case 3:                                                                                                                                
                                        scanf("%[^\n]",employees[i].details[1]);                                                                                       
                                        break;                                                                                                                         
                                case 4:                                                                                                                                
                                        scanf("%d",&employees[i].age);                                                                                                 
                                        break;                                                                                                                         
                                case 5:                                                                                                                                
                                        scanf("%d",&employees[i].salary);                                                                                              
                                        break;
                                default:                                                                                                                               
                                        printf("\nERROR IN OPTION SELECTION\n");                                                                                       
                        }                                                                                                                                              

                        sprintf(s[k],"%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i].salary); 
                }                                                                                                                                                      
                else                                                                                                                                                   
                        sprintf(s[k],"%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i].salary); 
               k++;                                                                                                                                                    
        }                                                                                                                                                              
        fp=fopen("employees.txt","w");//writing to the file after editing                                                                                              
        for(i=0;i<n+2;i++)                                                                                                                                             
        {                                                                                                                                                              
                fprintf(fp,"%s",s[i]);                                                                                                                                 
        }                                                                                                                                                              
        if(flag!=1)                                                                                                                                                    
                printf("\nEDITING DONE SUCCESSFULLY\n");                                                                                                               
        else                                                                                                                                                           
                printf("\nERROR OCCURRED\n");                                                                                                                          
        fclose(fp);                                                                                                                                                    
}                                                                                                                                                                      
void delete()                                                                                                                                                          
{                                                                                                                                                                      
        FILE* fp1;                                                                                                                                                     
        int n=0,id,i,flag=1,k=2;                                                                                                                                       
        printf("\nENTER THE EMPLOYEE ID TO DELETE: ");                                                                                                                 
        scanf("%d",&id);                                                                                                                                               
        fp=fopen("employees.txt","r");                                                                                                                                 
        fp1=fopen("temp.txt","w");//opening a new file and writing to it                                                                                               
        for(i=0;i<2;i++)                                                                                                                                               
        {                                                                                                                                                              
                fgets(s[i],200,fp);                                                                                                                                    
                fprintf(fp1,"%s",s[i]);                                                                                                                                
        }                                                                                                                                                              
        while(fscanf(fp,"%d %s %d %s %d",&employees[n].no,employees[n].details[0],&employees[n].age,employees[n].details[1],&employees[n].salary)==5)                  
        {                                                                                                                                                              
                n++;                                                                                                                                                   
        }                                                                                                                                                              
        fclose(fp);                                                                                                                                                    
        for(i=0;i<n;i++)                                                                                                                                               
        {                                                                                                                                                              
                if(id==employees[i].no)                                                                                                                                
                {                                                                                                                                                      
                        flag=0;                                                                                                                                        
                }                                                                                                                                                      
                else                                                                                                                                                   
                {                                                                                                                                                      
                        fprintf(fp1,"%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i].salary);  
                }                                                                                                                                                      
        }                                                                                                                                                              
        fclose(fp1);                                                                                                                                                   
        rename("temp.txt","employees.txt");//renaming to ensure its the same file                                                                                      
        if(flag!=1)
                printf("\nDELETION DONE SUCCESSFULLY\n");                                                                                                              
        else                                                                                                                                                           
                printf("\nENCOUNTERED ERROR\n");                                                                                                                       
}                                                                                                                                                                      
void list()                                                                                                                                                            
{                                                                                                                                                                      
        int n,k,j,i,flag=1;                                                                                                                                            
        char id[35];                                                                                                                                                   
        fp=fopen("employees.txt","r");                                                                                                                                 
        for(i=0;i<2;i++)                                                                                                                                               
        {                                                                                                                                                              
                fgets(word,200,fp);                                                                                                                                    
        }                                                                                                                                                              
        while(fscanf(fp,"%d %s %d %s %d",&employees[n].no,employees[n].details[0],&employees[n].age,employees[n].details[1],&employees[n].salary)==5)                  
        {                                                                                                                                                              
                n++;                                                                                                                                                   
        }                                                                                                                                                              
        printf("\n1.ID\n2.AGE\n3.SALARY\n4.DESIGNATION\n5.NAME\n");                                                                                                    
        printf("\nENTER THE DISTINCT SEARCHING ELEMENT: ");                                                                                                            
        scanf("%d",&j);                                                                                                                                                
        getchar();                                                                                                                                                     
        switch(j)                                                                                                                                                      
        {                                                                                                                                                              
                case 1:                                                                                                                                                
                        printf("ENTER THE ID\t: ");                                                                                                                    
                        scanf("%d",&k);                                                                                                                                
                        for(i=0;i<n;i++)                                                                                                                               
                        {                                                                                                                                              
                                if(k==employees[i].no)//listing based on the details given by the user                                                                 
                                {                                                                                                                                      
                                        printf("\nAT INDEX %d \n-------------------------------------------------------------------------------------------------------
----------------------------------------\n",i+1);                                                                                                                      
                                        printf("%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i]
.salary);                                                                                                                                                              
                                        flag=0;                                                                                                                        
                                }                                                                                                                                      
                        }                                                                                                                                              
                        break;                                                                                                                                         
                case 2:                                                                                                                                                
                        printf("ENTER THE AGE\t: ");                                                                                                                   
                        scanf("%d",&k);                                                                                                                                
                        for(i=0;i<n;i++)                                                                                                                               
                        {                                                                                                                                              
                                if(k==employees[i].age)                                                                                                                
                                {                                                                                                                                      
                                        printf("\nAT INDEX %d\n--------------------------------------------------------------------------------------------------------
---------------------------------------\n",i+1);                                                                                                                       
                                        printf("%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i]
.salary);                                                                                                                                                              
                                        flag=0;                                                                                                                        
                                }                                                                                                                                      
                        }                                                                                                                                              
                        break;                                                                                                                                         
                case 3:                                                                                                                                                
                        printf("ENTER THE SALARY\t: ");                                                                                                                
                        scanf("%d",&k);                                                                                                                                
                        getchar();                                                                                                                                     
                        for(i=0;i<n;i++)                                                                                                                               
                        {                                                                                                                                              
                                if(k==employees[i].salary)                                                                                                             
                                {                                                                                                                                      
                                        printf("\nAT INDEX %d\n--------------------------------------------------------------------------------------------------------
---------------------------------------\n",i+1);                                                                                                                       
                                        printf("%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i]
.salary);                                                                                                                                                              
                                        flag=0;                                                                                                                        
                                }                                                                                                                                      
                        }                                                                                                                                              
                        break;                                                                                                                                         
                case 4:                                                                                                                                                
                                                                                                                                                                       
                        printf("ENTER THE PROFESSION\t: ");                                                                                                            
                        gets(id);                                                                                                                                      
                        getchar();                                                                                                                                     
                        for(i=0;i<n;i++)                                                                                                                               
                        {                                                                                                                                              
                                if(strcmp(id,employees[i].details[1])==0)                                                                                              
                                {                                                                                                                                      
                                        printf("\nAT INDEX %d\n--------------------------------------------------------------------------------------------------------
---------------------------------------\n",i+1);                                                                                                                       
                                        printf("%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i]
.salary);                                                                                                                                                              
                                        flag=0;                                                                                                                        
                                }
                        }                                                                                                                                              
                        break;                                                                                                                                         
                case 5:                                                                                                                                                
                        printf("ENTER THE NAME\t: ");                                                                                                                  
                        gets(id);                                                                                                                                      
                        for(i=0;i<n;i++)                                                                                                                               
                        {                                                                                                                                              
                                if(strcmp(id,employees[i].details[0])==0)//comparing strings                                                                           
                                {                                                                                                                                      
                                        printf("\nAT INDEX %d\n--------------------------------------------------------------------------------------------------------
---------------------------------------\n",i+1);                                                                                                                       
                                        printf("%-31d%-24s%-23d%-30s%d\n",employees[i].no,employees[i].details[0],employees[i].age,employees[i].details[1],employees[i]
.salary);                                                                                                                                                              
                                        flag=0;                                                                                                                        
                                }                                                                                                                                      
                        }                                                                                                                                              
                        break;                                                                                                                                         
                default:                                                                                                                                               
                        printf("\nERROR IN OPTION SELECTION\n");                                                                                                       
        }                                                                                                                                                              
        fclose(fp);                                                                                                                                                    
        if(flag!=0)                                                                                                                                                    
                printf("\nNOT FOUND\n");                                                                                                                               
                                                                                                                                                                       
}                                                                                                                                                                      
        