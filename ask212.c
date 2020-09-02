//Tepelidis Avraam  AM:2008030104

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> /*Orismos ths synarthshs malloc*/
#include <string.h>

#define MAX_CHAR 40 /*Orismos tou maximum arithmou twn xarakthrwn toy onomatos enos ypalliloy */

//H domh poy periexei thn pliroforia gia ka8e ypallilo
struct employeeType {
	char *name;
	char *eidikotita;
	long misthos;
};

//int comp(const void *s1,const void *s2);

void main()
{
	FILE *sourcefile, *sourcefile2, *targetfile; //deiktes sta arxeia eisou-ejodoy
	int ch; //apo8ikeyei ton trexonta xaraktira keimenoy

	struct employeeType *employees=NULL;
	int nEmployees=0;
	int i;
	char key, input[80];     //PROSOXI, patiste 'n', to 'y' den douleuei!!!
		while ((key!='y') && (key!='n')){      //brogxos gia tin eisagwgi neou ergazomenou
			puts("Eisagwgi neou ergazomenoy?(y/n)");
			scanf("%c",&key);
			if (key=='y'){
				getchar();
				puts("dwse stoixeia ergazomenou me tin morfi: epwnymo ,onoma;eidikotita;misthos");
				gets(input);	
			}
		}
	sourcefile = fopen("/home/makis/Επιφάνεια εργασίας/employees.txt","a+"); //anoigma arxeioy eisodoy
	if (sourcefile == NULL) //an to arxeio den mporei na anoiksei...
		printf("Input file does not exist. Bye! \n");
	else
	{	
		if (key=='y')
			fprintf(sourcefile,"%s",input);
		fscanf(sourcefile,"%d\n", &nEmployees); //diavasma toy ari8moy twn ypallilwn
		if (key=='y')
			nEmployees++;
		//desmefsi toy aparaithtoy xwroy mnhmhs
		employees=(struct employeeType *)malloc(sizeof(struct employeeType)*nEmployees);
		for (i = 0; i < nEmployees; i++) {
        		employees[i].name = (char *) malloc(sizeof (char) * MAX_CHAR );
			employees[i].eidikotita = (char *) malloc(sizeof (char) * MAX_CHAR );
		}
		for(i=0;i<nEmployees;i++)
			fscanf(sourcefile,"%s %s %ld\n",employees[i].name, employees[i].eidikotita, &employees[i].misthos);
		for(i=0;i<nEmployees;i++) 
			printf("%s %s %ld\n", employees[i].name, employees[i].eidikotita, employees[i].misthos);

		//free(employees);
		fclose(sourcefile);

		//Taksinomisi
		    int sorted = 0, j = 0;
		    //struct employeeType temp[0];
			char *temp, *temp2;
			long temp3=0;
		
		    while(sorted != 1) {
		        sorted = 1;
		        for (j = 0; j < nEmployees - 1; j++) {
		            //printf("Now comparing string %s with string %s\n",employees[j].name,employees[j+1].name);
		            if (strcmp(employees[j].name, employees[j+1].name) > 0) {
		                sorted = 0;
		                temp = employees[j+1].name;
		                employees[j + 1].name = employees[j].name;
		                employees[j].name = temp;
		                temp2 = employees[j+1].eidikotita;
		                employees[j + 1].eidikotita = employees[j].eidikotita;
		                employees[j].eidikotita = temp2;
		                temp3 = employees[j+1].misthos;
		                employees[j + 1].misthos = employees[j].misthos;
		                employees[j].misthos = temp3;
		                //printf("A permutation happened.\n");
		            }
		        }
    		    }
		//Taksinomisi telos
		//--------------------------------//
		//qsort(employees.name,MAX_CHAR,sizeof(employees[0].name),comp);
		//sourcefile2 = fopen("/home/makis/Επιφάνεια εργασίας/employees.txt","r");
		//---------------------------------//
		targetfile = fopen("/home/makis/Επιφάνεια εργασίας/output.txt","w+"); //anoigma arxeioy ejodoy
		if (targetfile == NULL) //an to arxeio den mporei na anoiksei...
			printf("Output file can't be open. Bye! \n");
		else
		{
			for(i=0;i<nEmployees;i++)  //eggrafi sto neo arxeio meta apo taxinomisi
				fprintf(targetfile,"%s %s %ld\n", employees[i].name, employees[i].eidikotita, employees[i].misthos);
			/*--------------------------------------*/
			//while ((ch = getc(sourcefile2)) != EOF) //diavasma toy xaraktira
				//metatropi toy xaraktira se kefalaio kai grapsimo sto arxeio ejodoy
			//	putc(ch, targetfile);
			//if (fclose(sourcefile2)) printf("The input file was not closed\n"); //kleisimo arxeioy eisodoy
			/*-------------------------------------*/
			if (fclose(targetfile)) printf("The output file was not closed\n"); //kleisimo arxeioy ejodoy
			free(employees);//apodesmeysh ths mnhmhs poy desmeftike
		}
	}
}
/*---------------------------------------------*/
//int comp(const void *s1,const void *s2)
//{
//	return(strcmp(*(char **)s1, *(char **)s2));
//}