//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

double randfrom(double min, double max)
{
	double range = (max - min);
	double div = RAND_MAX / range;
	return min + (rand() / div);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

const int Pop = 200;
int Population = 200;
const int Dimension = 30;
int iteration,iter,F;

int     TmpFd,c,y,i,j,x,R1,R2,R3,say,p;
double  TmpP1,TmpP,TmpX1,TmpX2,TmpJ1,TmpJ2,TmpJ3,CRValue,FValue,TmpTT2,TmpTT,TmpTT3,TmpY,
TmpUF1,TmpUF2,TmpUF3,F1,F2,F3,n,RandX,TmpX,TmpPow ;
double  b,a,Range1,Range2,Range1x,Range2x,TmpR1,TmpR2 ;
String TmpStr;

double MatrixA[Pop][30];
double MatrixF1[Pop], MatrixF2[Pop],MatrixF3[Pop],MatrixV[30],MatrixU[30] ;

const double CRMatrix[6] = {0.2, 0.5, 0.8, 0.85, 0.9, 0.95};
const double FMatrix[8]  = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};


std::auto_ptr<TStrings> StringList(new TStringList());

iter= StrToInt(Txtiteration->Text)  ;
F=StrToInt(TxtFunction->Text);
if (F == 1)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}
else if (F == 2)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}
else if (F == 3)
	{
	Range1=0;
	Range2=1;
	Range1x=0;
	Range2x=1;
	}
else if (F == 4)
	{
	Range1=0;
	Range2=1;
	Range1x=-2;
	Range2x=2;
	}
else if (F == 5)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}
else if (F == 6)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}
else if (F == 7)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}
else if (F == 8)
	{
	Range1=0;
	Range2=1;
	Range1x=-2;
	Range2x=2;
	}

	 Series1->Clear();
	 Series2->Clear();
	 Series3->Clear();
	 Memo1->Clear();
	 srand(time(NULL));


				for (x = 0; x <= Population - 1; ++x)
					{
					 MatrixA[x][0] = randfrom(Range1,Range2);
					 TmpFd=1;
					 if (F==8)
					 {
					  MatrixA[x][1] = randfrom(Range1,Range2);
					  TmpFd=2;
					 }

					 for (i = TmpFd ; i <= Dimension - 1; ++i)
						 {
						  MatrixA[x][i] = randfrom(Range1x,Range2x);
						 }
					}

				 TmpUF2= 0; TmpUF3 = 0; TmpUF1=0; TmpTT=0; TmpTT2=0; TmpTT3=0;


				  if (F==1)  // 1. Problem
					 {
					 for (x = 0; x <= Population - 1; ++x)
						{
						  j=0; TmpTT=0; TmpTT3=0; TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

						  for (i = 0; i <= Dimension - 1; ++i)
							 {
							  j=i+1;
							  if (j>1  &&  31>j && j % 2 != 0)     //J1
							   {
								 TmpJ1=TmpJ1+1;
								 TmpTT2= (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (j>1  &&  31>j && j % 2 == 0)   //J2
							   {
								 TmpJ2  =  TmpJ2+1;
								 TmpTT2 =  (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT3 =  TmpTT3 + (TmpTT2*TmpTT2);
							   }

							 }

							  F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							  F2 = 1-  sqrt(TmpX1) + (2/TmpJ2) *TmpTT3 ;
							  MatrixF1[x]  = F1 ;
							  MatrixF2[x]  = F2 ;
							  MatrixF3[x]  = ( ( 1-  sqrt(F1) ) - F2 ) * ( ( 1-  sqrt(F1) ) - F2 ) ;
						}

					 }


				  else if (F == 2)  //2. Problem
					{
					  for (x=0; x<=Population -1; ++x)
						 {
						  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

						  for (i=0; i<=Dimension-1; ++i)
							 {
							  j=i+1;
							  if (j>1  &&  31>j && j % 2 != 0)    //J1
								{
								 TmpJ1=TmpJ1+1;
								 TmpTT2 = (
										   MatrixA[x][i] -
										   ( 0.3 * (TmpX1*TmpX1) * cos(24*M_PI*TmpX1 + (4*j*M_PI)/30) + 0.6*TmpX1 ) *
										   cos(6*M_PI*TmpX1 + (j*M_PI)/30)
										   );

								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
								}

							  if (j>1  &&  31>j && j % 2 == 0)     //j2
								 {
								 TmpJ2=TmpJ2+1;
								 TmpTT2 = (
										   MatrixA[x][i] -
										   ( 0.3 * (TmpX1*TmpX1) * sin(24*M_PI*TmpX1 + (4*j*M_PI)/30) + 0.6*TmpX1 ) *
										   cos(6*M_PI*TmpX1 + (j*M_PI)/30)
										   );

								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
								 }

							 }

							  F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							  F2 = 1-  sqrt(TmpX1) + (2/TmpJ2) *TmpTT3 ;
							  MatrixF1[x]  = F1 ;
							  MatrixF2[x]  = F2 ;
							  MatrixF3[x]  = ( ( 1-  sqrt(F1) ) - F2 ) * ( ( 1-  sqrt(F1) ) - F2 ) ;

						 }

					}
			   else if (F == 3) //3. Problem
				 {
				   for (x=0; x<=Population-1;++x)
					 {

					  j=0;  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpY=0; TmpP=1; TmpJ1=0; TmpJ2=0;

					   for (i=1; i<=Dimension-1; ++i)
						 {
						   j=i+1; TmpJ1=TmpJ1+1; TmpJ2=TmpJ2+1;
						   TmpX=StrToFloat(IntToStr(j));
						   TmpJ1=TmpJ1+1;

						   if (TmpX1==0) TmpPow = 0 ;
						   else TmpPow = pow(TmpX1,(0.5*(1+  ( 3*(j-2) / (30-2) ) ) ) ) ;

						   TmpY = MatrixA[x][i]- TmpPow ;

						   TmpP =TmpP* cos((20*TmpY*i*M_PI)/sqrt(TmpX)) ;
						   TmpTT=TmpTT + (TmpY*TmpY);
						 }

					 MatrixF1[x]  = TmpX1 + (2/TmpJ1) * ( (4*TmpTT) - (2*TmpP) + 2 ) ;
					 MatrixF2[x] = 1-sqrt(TmpX1) + (2/TmpJ2) *  ( (4*TmpTT) - (2*TmpP) + 2 );
					 }
				 }

				else if (F == 4) // 4. Problem
				 {
				  for (x=0; x<=Population-1; ++x)
					{
					  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;
					  for (i=0; i<=Dimension-1; ++i)
						 {
						   j=i+1;
						   if (j>1  &&  31>j && j % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = fabs(TmpY) / ( 1+ exp(2*fabs(TmpY)) ) ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (j>1  &&  31>j && j % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = fabs(TmpY) / ( 1+ exp(2*fabs(TmpY)) )  ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 MatrixF1[x]  = TmpX1 + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] =  1-(TmpX1*TmpX1) + (2/TmpJ2) * TmpTT3;
					}
				 }


				else if (F == 5) // 5. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-1; ++i)
						 {
						   j=i+1;
						   if (j>1  &&  31>j && j % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (j>1  &&  31>j && j % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 MatrixF1[x]  = TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] = 1- TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ2) * TmpTT3 ;
					}
				}

				else if (F == 6) // 6. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0];  TmpP=1; TmpP1=1; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-1; ++i)
						 {
						   j=i+1;
						   TmpX=StrToFloat(IntToStr(j));
						   if (j>1  &&  31>j && j % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpP = TmpP * cos( (20*TmpY*M_PI) / sqrt(TmpX) ) ;
							  TmpTT  = TmpTT + (TmpY*TmpY);
							  }

						   if (j>1  &&  31>j && j % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpP1 = TmpP1 * cos( (20*TmpY*M_PI) / sqrt(TmpX) ) ;
							  TmpTT3  = TmpTT3 + (TmpY*TmpY);
							  }

						 }
						 MatrixF1[x] = TmpX1 +  max(0.0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ1) *  ( 4*TmpTT - 2*TmpP + 2);
						 MatrixF2[x] = 1- TmpX1 +  max(0.0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ2) *  ( 4*TmpTT3 - 2*TmpP1 + 2);
					}
				}

				else if (F == 7) // 7. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-1; ++i)
						 {
						   j=i+1;
						   if (j>1  &&  31>j && j % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = TmpY*TmpY  ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (j>1  &&  31>j && j % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
							  TmpTT2 = TmpY*TmpY  ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 if (TmpX1==0) TmpPow = 0 ;
						 else TmpPow = pow(TmpX1,1/5) ;

						 MatrixF1[x] = TmpPow + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] = 1- TmpPow + (2/TmpJ2)  * TmpTT3 ;
					}
				}
				else if (F == 8) // 8. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  j=0; TmpTT=0; TmpTT2=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpX2=MatrixA[x][1]; TmpJ1=0; TmpJ2=0; TmpJ3=0;

					  for (i=0; i<=Dimension-1; ++i)
						 {
						   j=i+1;
						   if (j>1  &&  31>j &&  (j-1) % 3 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
							  TmpTT  = TmpTT + (TmpY*TmpY) ;
							  }

						   if (j>1  &&  31>j && (j-2) % 3 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
							  TmpTT2  = TmpTT2 + (TmpY*TmpY) ;
							  }

						   if (j>1  &&  31>j && j % 3 == 0) //J3
							  {
							  TmpJ3=TmpJ3+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
							  TmpTT3  = TmpTT3 + (TmpY*TmpY) ;
							  }

						 }
						 MatrixF1[x] = cos(0.5*TmpX1*M_PI)*cos(0.5*TmpX2*M_PI)+2/TmpJ1 * TmpTT ;
						 MatrixF2[x] = cos(0.5*TmpX1*M_PI)*sin(0.5*TmpX2*M_PI)+2/TmpJ2 * TmpTT2 ;
						 MatrixF3[x] = sin(0.5*TmpX1*M_PI)+2/TmpJ3 * TmpTT3 ;
					}
				}


			 iteration = iter;  c=0;   //&& Population < 300 && Population>0
			 while (iteration>0  )
				 {
					  R1=randfrom(0,Population) ;
					  R2=randfrom(0,Population) ;
					  R3=randfrom(0,Population) ;

					  //CRValue = randfrom(0.1,0.95);
					  //FValue  = randfrom(0.1,0.95);

					   CRValue = 0.9;  FValue  = 0.7;

					   for (x = 0; x <= Dimension - 1; ++x)
						   {
							MatrixV[x] = MatrixA[R1][x] + ( FValue*(MatrixA[R2][x]-MatrixA[R3][x] ) ) ;
						   }

					   for (x = 0; x <= Dimension - 1; ++x)
						   {
							RandX = randfrom(0,1);
							if (CRValue > RandX )
							   {
									if (x<TmpFd)
									  {
									   TmpR1=Range1; TmpR2=Range2;
									  }
									else
									   {
									   TmpR1=Range1x; TmpR2=Range2x;
									   }

									if (MatrixV[x]>TmpR2)
									   {
										MatrixU[x] = TmpR2 ;
									   }
										else if (MatrixV[x]<TmpR1)
										  {
										   MatrixU[x] = TmpR1;
										  }
										  else
											{
											 MatrixU[x] = MatrixV[x] ;
											}
							   }
								else {
									 MatrixU[x] = MatrixA[R1][x];
									 }

						   }

						TmpUF1=0; TmpTT=0; TmpTT2=0; TmpTT3=0;
					   if (F==1)  // 1. Problem
						 {

						  j=0; TmpTT=0; TmpTT3=0; TmpX1=(MatrixU[0]); TmpJ1=0; TmpJ2=0;

						  for (x = 0; x <= Dimension - 1; ++x)
							 {
							  j=x+1;
							  if (j>1  &&  31>j && j % 2 != 0)     //J1
							   {
								 TmpJ1=TmpJ1+1;
								 TmpTT2 = (MatrixU[x] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT  = TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (j>1  &&  31>j && j % 2 == 0)   //J2
							   {
								 TmpJ2=TmpJ2+1;
								 TmpTT2= (MatrixU[x] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
							   }

							 }

							  F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							  F2 = 1-  sqrt(TmpX1) + (2/TmpJ2) *TmpTT3 ;
							  TmpUF1  = F1 ;
							  TmpUF2  = F2 ;
							  TmpUF3  = ( ( 1-  sqrt(F1) ) - F2 ) * ( ( 1-  sqrt(F1) ) - F2 ) ;

						 }
					  else if (F == 2)  //2. Problem
						{
							  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpJ1=0; TmpJ2=0;

							  for (x=0; x<=Dimension-1; ++x)
								 {
								  j=x+1;
								  if (j>1  &&  31>j && j % 2 != 0)    //J1
									{
									 TmpJ1=TmpJ1+1;
									 TmpTT2 = (
											   MatrixU[x] -
											   ( 0.3 * (TmpX1*TmpX1) * cos(24*M_PI*TmpX1 + (4*j*M_PI)/30) + 0.6*TmpX1 ) *
											   cos(6*M_PI*TmpX1 + (j*M_PI)/30)
											   );

									 TmpTT=TmpTT + (TmpTT2*TmpTT2);
									}

								  if (j>1  &&  31>j && j % 2 == 0)     //j2
									 {
									 TmpJ2=TmpJ2+1;
									 TmpTT2 = (
											   MatrixU[x] -
											   ( 0.3 * (TmpX1*TmpX1) * sin(24*M_PI*TmpX1 + (4*j*M_PI)/30) + 0.6*TmpX1 ) *
											   cos(6*M_PI*TmpX1 + (j*M_PI)/30)
											   );

									 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
									 }

								 }

							  F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							  F2 = 1-  sqrt(TmpX1) + (2/TmpJ2) *TmpTT3 ;
							  TmpUF1  = F1 ;
							  TmpUF2  = F2 ;
							  TmpUF3  = ( ( 1-  sqrt(F1) ) - F2 ) * ( ( 1-  sqrt(F1) ) - F2 ) ;

						}
				   else if (F == 3) //3. Problem
					 {
						   j=0;	TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpY=0; TmpP=1; TmpJ1=0; TmpJ2=0;
						   for (x=1; x<=Dimension-1; ++x)
							 {
							   j=x+1; TmpJ1=TmpJ1+1; TmpJ2=TmpJ2+1;
							   TmpX=StrToFloat(IntToStr(j));
							   TmpJ1=TmpJ1+1;

							   if (TmpX1==0) TmpPow = 0 ;
							   else TmpPow = pow(TmpX1,(0.5*(1+  ( 3*(j-2) / (30-2) ) ) ) ) ;

							   TmpY = MatrixU[x]-TmpPow ;
							   TmpP =TmpP* cos((20*TmpY*j*M_PI)/sqrt(TmpX)) ;
							   TmpTT=TmpTT + (TmpY*TmpY);
							 }

						 F1  = TmpX1 + (2/TmpJ1) * ( (4*TmpTT) - (2*TmpP) + 2 ) ;
						 F2 = 1-sqrt(TmpX1) + (2/TmpJ2) *  ( (4*TmpTT) - (2*TmpP) + 2 );
						 TmpUF1  = F1 ;
						 TmpUF2  = F2 ;
					 }

					else if (F == 4) // 4. Problem
					 {
						  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpJ1=0; TmpJ2=0;
						  for (x=0; x<=Dimension-1; ++x)
							 {
							   j=x+1;
							   if (j>1  &&  31>j && j % 2 != 0)  //J1
								  {
								  TmpJ1=TmpJ1+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = fabs(TmpY) / ( 1+ exp(2*fabs(TmpY)) ) ;
								  TmpTT  = TmpTT + (TmpTT2);
								  }

							   if (j>1  &&  31>j && j % 2 == 0) //J2
								  {
								  TmpJ2=TmpJ2+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = fabs(TmpY) / ( 1+ exp(2*fabs(TmpY)) ) ;
								  TmpTT3 = TmpTT3 + (TmpTT2);
								  }

							 }
							 F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							 F2 = 1-(TmpX1*TmpX1) + (2/TmpJ2) * TmpTT3;
							 TmpUF1  = F1 ;
							 TmpUF2  = F2 ;
					 }


					else if (F == 5) // 5. Problem
					{

						  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpJ1=0; TmpJ2=0;

						  for (x=0; x<=Dimension-1; ++x)
							 {
							   j=x+1;
							   if (j>1  &&  31>j && j % 2 != 0)  //J1
								  {
								  TmpJ1=TmpJ1+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
								  TmpTT  = TmpTT + (TmpTT2);
								  }

							   if (j>1  &&  31>j && j % 2 == 0) //J2
								  {
								  TmpJ2=TmpJ2+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
								  TmpTT3 = TmpTT3 + (TmpTT2);
								  }

							 }
							 F1 = TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ1) * TmpTT ;
							 F2 = 1- TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ2) * TmpTT3 ;
							 TmpUF1 = F1;
							 TmpUF2 = F2;

					}
					else if (F == 6) // 6. Problem
					{

						  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0];  TmpP=1; TmpP1=1; TmpJ1=0; TmpJ2=0;

						  for (x=0; x<=Dimension-1; ++x)
							 {
							   j=x+1;
							   TmpX=StrToFloat(IntToStr(j));
							   if (j>1  &&  31>j && j % 2 != 0)  //J1
								  {
								  TmpJ1=TmpJ1+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpP = TmpP * cos( (20*TmpY*M_PI) / sqrt(TmpX) ) ;
								  TmpTT  = TmpTT + (TmpY*TmpY);
								  }

							   if (j>1  &&  31>j && j % 2 == 0) //J2
								  {
								  TmpJ2=TmpJ2+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpP1 = TmpP1 * cos( (20*TmpY*M_PI) / sqrt(TmpX) ) ;
								  TmpTT3  = TmpTT3 + (TmpY*TmpY);
								  }

							 }
							 F1 = TmpX1 +  max(0.0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ1) *  ( 4*TmpTT - 2*TmpP + 2);
							 F2 = 1- TmpX1 +  max(0.0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ2) *  ( 4*TmpTT3 - 2*TmpP1 + 2);
							 TmpUF1 = F1 ;
							 TmpUF2 = F2 ;

					}

					else if (F == 7) // 7. Problem
					{

						  j=0; TmpTT=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpJ1=0; TmpJ2=0;

						  for (x=0; x<=Dimension-2; ++x)
							 {
							   j=x+1;
							   if (j>1  &&  31>j && j % 2 != 0)  //J1
								  {
								  TmpJ1=TmpJ1+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = TmpY*TmpY  ;
								  TmpTT  = TmpTT + (TmpTT2);
								  }

							   if (j>1  &&  31>j && j % 2 == 0) //J2
								  {
								  TmpJ2=TmpJ2+1;
								  TmpY   = MatrixU[x] -  sin(6*M_PI*TmpX1 + ((j*M_PI)/30) ) ;
								  TmpTT2 = TmpY*TmpY  ;
								  TmpTT3 = TmpTT3 + (TmpTT2);
								  }

							 }
							 if (TmpX1==0) TmpPow = 0 ;
							 else TmpPow = pow(TmpX1,1/5) ;

							 F1  = TmpPow + (2/TmpJ1) * TmpTT ;
							 F2 = 1- TmpPow + (2/TmpJ2)  * TmpTT3 ;
							 TmpUF1=F1;
							 TmpUF2=F2;
					}

					else if (F == 8) // 8. Problem
					{

						  j=0; TmpTT=0; TmpTT2=0; TmpTT3=0;  TmpX1=MatrixU[0]; TmpX2=MatrixU[1]; TmpJ1=0; TmpJ2=0; TmpJ3=0;

						  for (x=0; x<=Dimension-2; ++x)
							 {
							   j=x+1;
							   if (j>1  &&  31>j &&  (j-1) % 3 != 0)  //J1
								  {
								  TmpJ1=TmpJ1+1;
								  TmpY = MatrixU[x] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
								  TmpTT  = TmpTT + (TmpY*TmpY) ;
								  }

							   if (j>1  &&  31>j && (j-2) % 3 == 0) //J2
								  {
								  TmpJ2=TmpJ2+1;
								  TmpY = MatrixU[x] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
								  TmpTT2  = TmpTT2 + (TmpY*TmpY) ;
								  }

							   if (j>1  &&  31>j && j % 3 == 0) //J3
								  {
								  TmpJ3=TmpJ3+1;
								  TmpY = MatrixU[x] - (2*TmpX2*sin(2*M_PI*TmpX1 + (j*M_PI) /30) );
								  TmpTT3  = TmpTT3 + (TmpY*TmpY) ;
								  }

							 }
							 F1 = cos(0.5*TmpX1*M_PI)*cos(0.5*TmpX2*M_PI)+2/TmpJ1 * TmpTT ;
							 F2 = cos(0.5*TmpX1*M_PI)*sin(0.5*TmpX2*M_PI)+2/TmpJ2 * TmpTT2 ;
							 F3 = sin(0.5*TmpX1*M_PI)+2/TmpJ3 * TmpTT3 ;
							 TmpUF1=F1;
							 TmpUF2=F2;
							 TmpUF3=F3;
					}




				   if (MatrixF1[R1] > TmpUF1 && MatrixF2[R1] > TmpUF2 )
					  {
						   MatrixF1[R1] = TmpUF1 ;
						   MatrixF2[R1] = TmpUF2 ;

						   for (x=0; x<=Dimension-1;++x)
							  {
							   MatrixA[R1][x] = MatrixU[x] ;
							  }
					  }

			 //   yapýlanlarý topla bu güne kadar onlarý göster  bu þimdiki algoritma temel algoritmadýr
			//    fonksiyonlarý birleþrtitdeik . 1 tane aldýk içinden 100 unu seçtik
			//

				  --iteration ;
				 } //iteration


		TmpStr="";
		for (x = 0; x <=  Population- 1; ++x)
			{
			 for (i = 0; i <= Dimension - 1; ++i)
				 {
				  TmpStr =  TmpStr + MatrixA[x][i] + "\t";
				 }
				StringList->Add(TmpStr) ;
				TmpStr="";


				 Series2->AddXY(MatrixF1[x],MatrixF2[x]);
			}
			ShowMessage(Population);
			ShowMessage(iteration);

 if (F == 1)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- sqrt(a));
		}
	}

else if (F == 2)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- sqrt(a));
		}
	}

else if (F == 3)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- sqrt(a));
		}
	}

else if (F == 4)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- (a*a));
		}
	}

else if (F == 5)
	{	 for (a=0; a<=20 ;++a)
		{
		  Series1->AddXY(a/20,1- (a/20));
		}
	}
else if (F == 6)
	{	 for (a=1; a<=2 ;++a)
		{
		   for (b=((2*a-1)/4); b<=(2*a/4) ;b=0.01+b)
			  {
				Series1->AddXY(b,1- b);
			  }
		}
	}
else if (F == 7)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- a);
		}
	}
else if (F == 8)
	{	 for (a=0; a<=1 ;a=0.01+a)
		{
		  Series1->AddXY(a,1- a);
		}
	}
	  StringList->SaveToFile("test.txt");
	  ShowMessage("ok");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Series1->Clear();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Memo1->Lines->SaveToFile("test.txt");
}
//---------------------------------------------------------------------------

