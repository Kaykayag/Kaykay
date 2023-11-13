#include <stdio.h>
// two constant
#define LABOR_RATE 0.35
#define TAX_RATE 0.085

//function declaration
int calculateArea(int l, int w);
double installedPrice(int cost,int area);
double calculateSubTotal(int discount, double y);
double calculateTotalPrice(double x);
void putMeasurement(int l, int w, int area);
void putCharges(int cost,int discount,int area, double install , double sub, double total);

int main()
{
//local declaration
int length,width,discount,costPerSqFt,area;
double getInstalled,getSubTotal,getTotalPrice;

printf("Input the Length of room(ft)\t\t\n");
scanf("%d",&length);
printf("Input the Width of room(ft)\t\t\n");
scanf("%d",&width);
printf("Input the customer discount(percent)\t\t\n");
scanf("%d",&discount);
printf("Input the cost per square foot \t\t\n");
scanf("%d",&costPerSqFt);

area= calculateArea(length,width);

getInstalled= installedPrice(costPerSqFt,area);
getSubTotal=calculateSubTotal(discount,getInstalled);
getTotalPrice=calculateTotalPrice(getSubTotal);

//call the two function of the 
putMeasurement(length,width,area);
putCharges(costPerSqFt,discount,area,getInstalled,getSubTotal,getTotalPrice);
return 0;
}

//definiion
int calculateArea(int l, int w)
{
return l*w;
}
double installedPrice (int cost,int area)
{
return (cost*area)+(LABOR_RATE*area);

}
double calculateSubTotal( int discount, double y)
{
return y-(y*discount/100.0);

}
double calculateTotalPrice(double x)
{
return x+TAX_RATE;
}
void putMeasurement(int l, int w, int area)
{
//naa ari ang measurement
printf("\tMEASUREMENT\t\t\n");
printf("Length\t\t\t%dft\n",l);
printf("Width\t\t\t%dft\n",w);
printf("Area\t\t\t%dft\n",area);
return;
}
//naa ari ang charges
void putCharges(int cost,int discount,int area,double install, double sub, double total)
{
double chargeCost,chargeLabor,chargeDiscount,chargeTax;

chargeCost=cost*area;
chargeLabor=LABOR_RATE*area;
chargeDiscount=install-(install*discount/100.0);
chargeTax=TAX_RATE+sub;

printf("\tCHARGES\t\t\n");
printf("DESCRIPTION \tCOST/SQ. FT.\tCHARGE\n");
printf("-----------\t------------\t------\n");
printf("Carpet\t\t%.2d\t\t$%.2lf\n",cost,chargeCost);
printf("Labor\t\t0.35\t\t%.2lf\n",chargeLabor);
printf("\t\t\t\t------\n");
printf("INSTALLED PRICE\t\t\t$%.lf\n",install);
printf("discount\t%d%%\t\t%.2lf\n",discount,chargeDiscount);
printf("\t\t\t\t------\n");
printf("SUBTOTAL:\t\t\t$%.2lf\n",sub);
printf("TAX\t\t\t\t%.2lf\n",chargeTax);
printf("TOTAL\t\t\t\t$%.2lf\n",total);
return;
}