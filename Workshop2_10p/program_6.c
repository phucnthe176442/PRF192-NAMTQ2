/*
 * program 6
 * program_6.c
 * Nguyen Tri Phuc - HE176442
 * 28-5-2022
 */
#include<stdio.h>
#define pa 11000000 /// persional pending amount 
#define pd 4400000 /// alimony for each dependent
#define rate1 60000000 /// level 1 pre-defined
#define rate2 120000000 /// level 2 pre-defined
#define rate3 216000000 /// level 3 pre-defined

int main()
{
    /* Implement */
    int Number;
    do
    {
    	printf("Enter the number of households: ");
        scanf("%d", &Number);
        
        int i;
        for(i=1; i<=Number; ++i)
        {
            /* Input */
            printf("\nHousehold %d:\n", i);
            printf("Income of this year: ");
            double Income;
            scanf("%lf", &Income);

            printf("Number of dependent: ");
            int Number_dependents;
            scanf("%d", &Number_dependents);
            /* Input */

            /* Solve task */
            double Tax_free = 12 * (pa + Number_dependents * pd); /// calculate tax-free income

            double Taxable = Income - Tax_free; /// calculute taxable income
            if(Taxable < 0) /// check if meet special condition
                Taxable = 0;

			/* calculate income tax (4 cases) */
            double Income_tax = 0; 
            if(Taxable <= rate1)
    			Income_tax = Taxable*0.05;
			else if(rate1 < Taxable && Taxable <= rate2)
				Income_tax = (Taxable-rate1)*0.1 + rate1*0.05;
			else if(rate2 < Taxable && Taxable <= rate3)
				Income_tax = (Taxable-rate2)*0.15 + (rate2-rate1)*0.1 + rate1*0.05;
			else Income_tax = (Taxable-rate3)*0.2 + (rate3-rate2)*0.15 + (rate2-rate1)*0.1 + rate1*0.05;
            /* End of Task */

            /* Output */
            printf("Income tax of Household %d: %lf VND\n", i, Income_tax);
            /* End of Output */
        }
        printf("\n");
    }
    while(Number);
    /* End of Implement */

    return 0;
}



