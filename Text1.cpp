#include <fstream.h>         
#include <graphics.h>
#include <stdlib.h>
#include <process.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <complex.h>
#include <dos.h>
#define float double
float scale=1;
void axis(float a=scale)
{
	 float x=319,z=319,y=239,q=239;
	 line(319,0,319,479);
	 line(0,239,679,239);
	 outtextxy(x,y,"|");
	 outtextxy(x,y+10,"0");
	 x+=scale*40;
	 z-=scale*40;
	 if(a!=0.25)
	{ for(float i=1;i<=(8/scale) ;i++)
	 {
		outtextxy(x,y,"|");
		char s[5];
		gcvt(i,2,s);
		outtextxy(x,y+10,s);
		outtextxy(z,y,"|");
		gcvt(-1*i,2,s);
		outtextxy(z,y+10,s);
	       x+=scale*40;
	       z-=scale*40;

		}
		x=319;
		y-=scale*40;
		q+=scale*40;
		for(i=1;i<=(8/scale);i++)
		{
			outtextxy(x,y,"-");
		char s[5];
		gcvt(i,2,s);
		outtextxy(x+5,y,s);
		outtextxy(x,q,"-");
		gcvt(-1*i,2,s);
		outtextxy(x+5,q,s);
	       y-=scale*40;
	       q+=scale*40;
     }
      }

      else	{
	for(float i=1;i<=(8/scale) ;i+=2)
	 {
		outtextxy(x,y,"|");
		char s[5];
		gcvt(i,2,s);
		outtextxy(x,y+10,s);
		outtextxy(z,y,"|");
		gcvt(-1*i,2,s);
		outtextxy(z,y+10,s);
	       x+=scale*80;
	       z-=scale*80;

		}
		x=319;
		y-=scale*80;
		q+=scale*80;
		for(i=1;i<=(8/scale);i+=2)
		{
			outtextxy(x,y,"-");
		char s[5];
		gcvt(i,2,s);
		outtextxy(x+5,y,s);
		outtextxy(x,q,"-");
		gcvt(-1*i,2,s);
		outtextxy(x+5,q,s);
	       y-=scale*80;
	       q+=scale*80;
     }
      }
}


void convert(char s[],float a[])
{
      int f=0;
      char k='0'; int w=0;
      for(int i=0;s[i]!='(';i++);
      for(;s[i]!='\0';i++)
      {
	if(s[i]=='-')
		     {
			if(((s[i]=='-')&&((s[i-1]=='+')||(s[i-1]=='-')||(s[i-1]=='*')||(s[i-1]=='/')||(s[i-1]=='(')||(s[i-1]=='^'))))
			{
			     f=1;
			     for(int j=i;s[j]!='\0';j++)
			     {
				s[j]=s[j+1] ;
			     }
			}
		      }
	if(((s[i]<='9')&&(s[i]>='0')))
		{

				char t[100];
			int j=0;
			for(;(s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/')&&(s[i]!='^')&&(s[i]!=')');i++)

			{
					t[j]=s[i];
					j++;

			}


			t[j]='\0';
		       if(f==1)	a[w]=-1*atof(t);
		       else  a[w]=atof(t);

			i=i-1;
			for(;(s[i-1]!='(')&&(s[i-1]!='+')&&(s[i-1]!='-')&&(s[i-1]!='*')&&(s[i-1]!='/')&&(s[i-1]!='^') ;i-- )
				{
					for(int m=i;s[m]!='\0';m++)
					{
						s[m]=s[m+1];
					}
				}

			s[i]=k;

			k++;
			w++;
		   }

	}

}



float evaluate(char s[],float x,float a[])

{
	char 	t[100];
	char 	stack[100],result[100];
	int 	c1=0,c2=0;
	int kk=0;
	for(int j=0;s[j]!='(';j++);

	for(;s[j]!='\0';j++,kk++)
	{
		t[kk]=s[j];
		switch(t[kk])
		{
			case '(':
					{
						stack[c1]= '(';
						c1++;
					}break;
			case 'x':case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
					{
						result[c2]=t[kk] ;
						c2++;
					}break;
			case '+':case '-':
						{
						   for( c1=c1-1;stack[c1]!='(';c1--)
						   {
							result[c2]=stack[c1];
							c2++;
						   }
						   stack[c1+1]=t[kk];
						   c1++;  c1++;
						} break;

			case '*':case '/': 	{
						   for(c1=c1-1;(stack[c1]!='(')&&(stack[c1]!='+')&&(stack[c1]!='-');c1--)
						   {
							result[c2]=stack[c1];
							c2++;
						   }
						   stack[c1+1]=t[kk];
						   c1+=2;
						 }  break;

		       case '^':		{
						   for( c1=c1-1;(stack[c1]!='(')&&(stack[c1]!='+')&&(stack[c1]!='-')&&(stack[c1]!='*')&&(stack[c1]!='/');c1--)
						   {
							result[c2]=stack[c1];
							c2++;
						   }

						   stack[c1+1]=t[kk];
						   c1++;  c1++;
						   }break;

		       case 's':case 'c':case 't':case 'l':{

						   for( c1=c1-1;(stack[c1]!='(')&&(stack[c1]!='+')&&(stack[c1]!='-')&&(stack[c1]!='*')&&(stack[c1]!='/')&&(stack[c1]!='^');c1--)
						   {
							result[c2]=stack[c1];

							c2++;
						   }

						   stack[c1+1]=t[kk];
						   c1++;
						   c1++;
						   }break;


		       case ')':         	{
						   for(c1=c1-1;(stack[c1]!='(');c1--)
						   {

							result[c2]=stack[c1];
							c2++;
						   }

						 }break;
						}

		}
		result[c2]='\0';
		c1=0;
/*		cout<<endl<<result<<endl<<c2;
	      */
		char evaluate[100];
		double result_ans=0;
		int c3=0;
		int k=0;
		while(c3<=c2-1)
		 {
		   switch(result[c3])
		    {
			 case 'x':case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case 'A':
				{
					    evaluate[c1]=result[c3];
					    c1++;
					    if(c1==1)
						{if(evaluate[c1-1]=='x')result_ans=x;
						 else result_ans=a[evaluate[c1-1]-48];
						 }

				}break;
		    case '-':	{

				    if((evaluate[c1-1]=='x')&&(evaluate[c1-2]!='x'))
				    {
					result_ans=a[evaluate[c1-2]-48]-x;
					c1-=2;
					evaluate[c1]='A'+k;
					a[17+k]=result_ans;
					c1++;
				    }
				    else	if((evaluate[c1-1]!='x')&&(evaluate[c1-2]!='x')){

												    result_ans=a[evaluate[c1-2]-48]-a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

													}
					 else	if((evaluate[c1-1]=='x')&&(evaluate[c1-2]=='x')){
												  result_ans=x-x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
												}
					     else	       if((evaluate[c1-1]!='x')&&(evaluate[c1-2]=='x')){
														   result_ans=x-a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
					     }break;
		    case '+':{
				    if((evaluate[c1-1]=='x')&&(evaluate[c1-2]!='x')){
											result_ans=a[evaluate[c1-2]-48]+x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
				    else	if((evaluate[c1-1]!='x')&&(evaluate[c1-2]!='x')){

												    result_ans=a[evaluate[c1-2]-48]+a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

													}
					 else	if((evaluate[c1-1]=='x')&&(evaluate[c1-2]=='x')){
												  result_ans=x+x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
												}
					     else	       if((evaluate[c1-1]!='x')&&(evaluate[c1-2]=='x')){
														   result_ans=a[evaluate[c1-1]-48]+x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
					     }break;

	    case 'c':{                    if(evaluate[c1-1]=='x'){
									result_ans=cos(x);
									c1--;
										evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
									   }

									    else
									    {		result_ans=cos(a[evaluate[c1-1]-48]);
											c1--;
										evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

									       }


					     }break;

	    case 's':{
						     if(evaluate[c1-1]=='x'){
									result_ans=sin(x);
									c1--;
										evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
									   }

								     else {
											result_ans=sin(a[evaluate[c1-1]-48]);
											c1--;


											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

									      }
					     }break;

	    case 't':{

									       if(evaluate[c1-1]=='x'){
									result_ans=tan(x);
									c1--;
										evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
									   }
								      else {
										result_ans=tan(a[evaluate[c1-1]-48]);
											c1--;


											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
									      }

					     }break;

	    case 'l':{                                      if(evaluate[c1-1]=='x'){
									result_ans=log10(x);
									c1--;
										evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
									   }


								   else{			result_ans=log10(a[evaluate[c1-1]-48]);
											c1--;


											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

									}
					     }break;

			case '*':   	{
				    if((evaluate[c1-1]=='x')&&(evaluate[c1-2]!='x')){
											result_ans=x*a[evaluate[c1-2]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
				    else	if((evaluate[c1-1]!='x')&&(evaluate[c1-2]!='x')){

												    result_ans=a[evaluate[c1-2]-48]*a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

													}
					 else	if((evaluate[c1-1]=='x')&&(evaluate[c1-2]=='x')){
												  result_ans=x*x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
												}
					     else	       if((evaluate[c1-1]!='x')&&(evaluate[c1-2]=='x')){
														   result_ans=x*a[evaluate[c1-1]-48];
											c1--;
										c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
					     }break;
		    case '/':
				{
				    if((evaluate[c1-1]=='x')&&(evaluate[c1-2]!='x')){
											result_ans=a[evaluate[c1-2]-48]/x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
				    else	if((evaluate[c1-1]!='x')&&(evaluate[c1-2]!='x')){

												    result_ans=a[evaluate[c1-2]-48]/a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;

													}
					 else	if((evaluate[c1-1]=='x')&&(evaluate[c1-2]=='x')){
												  result_ans=x/x;
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
												}
					     else	       if((evaluate[c1-1]!='x')&&(evaluate[c1-2]=='x')){
														   result_ans=x/a[evaluate[c1-1]-48];
											c1--;
											c1--;

											evaluate[c1]='A'+k;
											a[17+k]=result_ans;
											c1++;
											}
					     }break;
		    case '^': 	{
				    if((evaluate[c1-1]=='x')&&(evaluate[c1-2]!='x'))
				    {
					result_ans=pow(a[evaluate[c1-2]-48],x);
					c1--;
					c1--;
					evaluate[c1]='A'+k;
					a[17+k]=result_ans;
					c1++;
				    }
					else	if((evaluate[c1-1]!='x')&&(evaluate[c1-2]!='x'))
					{
						result_ans=pow(a[evaluate[c1-2]-48],a[evaluate[c1-1]-48]);
						c1--;
						c1--;
						evaluate[c1]='A'+k;
						a[17+k]=result_ans;
						c1++;
					}
					 else	if((evaluate[c1-1]=='x')&&(evaluate[c1-2]=='x'))
					 {
						result_ans=pow(x,x);
						c1--;
						c1--;
						evaluate[c1]='A'+k;
						a[17+k]=result_ans;
						c1++;
					 }
					 else   if((evaluate[c1-1]!='x')&&(evaluate[c1-2]=='x'))
					 {
							result_ans=pow(x,a[evaluate[c1-1]-48]);
						c1--;
						c1--;
						evaluate[c1]='A'+k;
						a[17+k]=result_ans;
						c1++;
					 }
				}break;

	  }
	  c3++; k++;

      }

	       /*	cout<<endl<<evaluate[0]<<endl<<result_ans;
		 */


	return result_ans;

}

int cx,cy,q1;
class mouse

{
	public:	REGS regs;
		int no_buttons;
		void show_mouse();
		void get_status();
		void hide_mouse();
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
			//cout<<"Error initializing mouse";
		}
}ob;
void mouse::show_mouse()
{
	regs.x.ax=0x01;
	int86(0x33,&regs,&regs);
}
void mouse::hide_mouse()
{
	regs.x.ax=0x02;
	int86(0x33,&regs,&regs);
}

void mouse::get_status()
{
	regs.x.ax=0x03;
	int86(0x33,&regs,&regs);
	while(q1!=1)
	{
		regs.x.ax=0x03;
		int86(0x33,&regs,&regs);









		q1=regs.x.bx;
		cx=regs.x.cx;
		cy=regs.x.dx;
	}
	q1=0;
      /*	cout<<cx<<" "<<cy;    */
}
void graph(char s[],float w[])
{

	 /*
	 line(319,0,319,479);
	 line(0,239,679,239);
	  */
	  axis();
	float a=319,x=319,y=239,z=0,r=0;
	setcolor(RED);

	for(int i=1;i<=4000;i++)
	{





	    for(int b1=0,p=0,flag=0,flag2=0;((flag==0)&&(s[p]!='\0'));p++)
		{
			if(p==1){
				if((s[p]=='+')||(s[p]=='*')||(s[p]=='/')||(s[p]=='^')||(s[p]==')'))flag=1;
				}
			switch(s[p])
			{
			case '(':b1++;break;
			case ')':b1--;break;
			case '+':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '*':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '/':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '-':if(((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^'))&&((s[p+1]<'0')||(s[p+1]>'9')))flag=1;break;
			}
		}
		if(b1!=0)flag=1;
		if(flag==1)flag=1;
		else
		{

			for(int q=0;(s[q]!='\0')&&(flag2==0);q++)
			{
				if(s[q]==')')
				{
					int j=q+1;
					if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0'))
					{
						flag2=-300;
					}
				}
				else if(s[q]=='.')
				{
					int j=q+1;
					int ff=-1;
					while((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!='\0')&&(ff==-1))
					{
						if(s[j]=='.')ff=0;
						j++;
					}
					if(ff==0)flag2=-300;
				}


				else if((s[q]=='0')||(s[q]=='x')||(s[q]=='1')||(s[q]=='2')||(s[q]=='3')||(s[q]=='4')||(s[q]=='5')||(s[q]=='6')||(s[q]=='7')||(s[q]=='8')||(s[q]=='9'))
				{

					int j=q+1;
					if((s[j]!='+')&&(s[j]!='x')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0')&&(s[j]!='0')&&(s[j]!='1')&&(s[j]!='2')&&(s[j]!='3')&&(s[j]!='4')&&(s[j]!='5')&&(s[j]!='6')&&(s[j]!='7')&&(s[j]!='8')&&(s[j]!='9')&&(s[j]!='.'))
					{
						flag2=-300;
					}
				}

			       else	 if(s[q]=='l')
				{
				   int j=q+1;
					if(s[j]=='(')
					{

						char mn[50];

						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,z,an);
						if(ans<=0)flag2=-200;

					}
					else if(s[j]=='0')
					{
						flag2=-200;
					}
				}
				else if(s[q]=='/')
				{
					int j=q+1;

					if(s[j]=='(')
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,z,an);

						if(ans==0)flag2=-200;

					}
					else	if((s[j]=='s')||(s[j]=='c')||(s[j]=='l')||(s[j]=='t'))
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+2)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,z,an);
						if(ans==0)flag2=-200;

					}
					else if((s[j]=='x'))
					{
					  if(z==0)	flag2=-200;
					}

					else if((s[j]=='0')&&(s[j+1]!='.'))
					{
						flag2=-200;
					}
				}



			  }

			  }

      if((flag==0)&&(flag2==0)){
	   line(x,y-40*evaluate(s,z,w)*scale,x+0.1,y-40*evaluate(s,z+(0.0025/scale),w)*scale);

      }

	    for(b1=0,p=0,flag=0,flag2=0;((flag==0)&&(s[p]!='\0'));p++)
	   {
		if(p==1){
				if((s[p]=='+')||(s[p]=='*')||(s[p]=='/')||(s[p]=='^')||(s[p]==')'))flag=1;
			}
		switch(s[p])
		{
			case '(':b1++;break;
			case ')':b1--;break;
			case '+':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '*':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '/':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '-':if(((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^'))&&((s[p+1]<'0')||(s[p+1]>'9')))flag=1;break;
		}
	   }
		if(b1!=0)flag=1;
		if(flag==1)flag=1;
		else
		{

			for(int q=0;(s[q]!='\0')&&(flag2==0);q++)
			{
				if(s[q]==')')
				{
					int j=q+1;
					if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0'))
					{
						flag2=-300;
					}
				}
				else if(s[q]=='.')
				{
					int j=q+1;
					int ff=-1;
					while((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!='\0')&&(ff==-1))
					{
						if(s[j]=='.')ff=0;
						j++;
					}
					if(ff==0)flag2=-300;
				}


				else if((s[q]=='0')||(s[q]=='x')||(s[q]=='1')||(s[q]=='2')||(s[q]=='3')||(s[q]=='4')||(s[q]=='5')||(s[q]=='6')||(s[q]=='7')||(s[q]=='8')||(s[q]=='9'))
				{

					int j=q+1;
					if((s[j]!='+')&&(s[j]!='x')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0')&&(s[j]!='0')&&(s[j]!='1')&&(s[j]!='2')&&(s[j]!='3')&&(s[j]!='4')&&(s[j]!='5')&&(s[j]!='6')&&(s[j]!='7')&&(s[j]!='8')&&(s[j]!='9')&&(s[j]!='.'))
					{
						flag2=-300;
					}
				}

			       else	 if(s[q]=='l')
				{
				   int j=q+1;
					if(s[j]=='(')
					{

						char mn[50];

						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,r,an);
						if(ans<=0)flag2=-200;

					}
					else if(s[j]=='0')
					{
						flag2=-200;
					}
				}
				else if(s[q]=='/')
				{
					int j=q+1;

					if(s[j]=='(')
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,r,an);

						if(ans==0)flag2=-200;

					}
					else	if((s[j]=='s')||(s[j]=='c')||(s[j]=='l')||(s[j]=='t'))
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+2)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,r,an);
						if(ans==0)flag2=-200;

					}
					else if((s[j]=='x'))
					{
					  if(r==0)	flag2=-200;
					}

					else if((s[j]=='0')&&(s[j+1]!='.'))
					{
						flag2=-200;
					}
				}


			 }
			  }
     if((flag==0)&&(flag2==0))
     {

	   line(a,y-40*evaluate(s,r,w)*scale,a-0.1,y-40*evaluate(s,r-(0.0025/scale),w)*scale);
      }

		setcolor(RED);
		 x+=0.1;
		a-=0.1;
		z=z+0.0025/scale;
		r-=0.0025/scale;
	 delay(1);
	}


}
void calc2()
{

	for(int i1=0;i1<640;i1++)
	{
		for(int j1=0;j1<480;j1++)

		       {
				putpixel(i1,j1,BLACK);
			}
	}

	 int x=150;
	 int y=150;
	 for(int i=0;i<=5;i++)
	 {
		line(x,150,x,400);
		line(150,y,400,y);
		x+=50;
		y+=50;
	 }
	 rectangle(150,100,400,150);
	 outtextxy(175,175,"1");
	 outtextxy(225,175,"2");
	 outtextxy(275,175,"3");
	 outtextxy(325,175,"/");
	 outtextxy(360,175,"Power");
	 outtextxy(175,225,"4");
	 outtextxy(225,225,"5");
	 outtextxy(275,225,"6");
	 outtextxy(325,225,"Sin");
	 outtextxy(375,225,"x");
	 outtextxy(175,275,"7");
	 outtextxy(225,275,"8");
	 outtextxy(275,275,"9");
	 outtextxy(325,275,"Cos");
	 outtextxy(351,275,"Delete");
	 outtextxy(175,325,".");
	 outtextxy(225,325,"0");
	 outtextxy(275,325,"=");
	 outtextxy(325,325,"Tan");
	 outtextxy(351,325,"(");
	 outtextxy(175,375,"+");
	 outtextxy(225,375,"-");
	 outtextxy(275,375,"*");
	 outtextxy(275,375,"");
	 outtextxy(310,375,"clear");
	 outtextxy(351,375,")");
	 rectangle(500,250,550,300);
	 outtextxy(510,275,"exit");
	     /*Make sure useless user enters properly*/
	 char s[400];
	 int counter=0,counter1=0;
	 s[counter]='(';
	 counter=1;
	 void mscreen();
	 ob.show_mouse();

	  while(s[counter]!='=')
	 {
		ob.get_status();
		if((cx>500)&&(cx<550)&&(cy>250)&&(cy<300))
			{
				mscreen();
				counter=1;
				counter1=0;
			}

		else     	if(((cx>=150)&&(cx<=200))&&((cy>=150)&&(cy<=200)))
		  {
			s[counter]='1';
			outtextxy(175+10*counter1,125,"1");
			counter1++;
		  }

	    else	  if(((cx>=200)&&(cx<=250))&&((cy>=150)&&(cy<=200)))
		  {
			s[counter]='2';
			outtextxy(175+10*counter1,125,"2");
				counter1++;
		  }
	    else	  if(((cx>=250)&&(cx<=300))&&((cy>=150)&&(cy<=200)))
		  {
			s[counter]='3';
			outtextxy(175+10*counter1,125,"3");
				counter1++;
		  }
	    else	if(((cx>=300)&&(cx<=350))&&((cy>=150)&&(cy<=200)))
		  {
			s[counter]='/';
			outtextxy(175+10*counter1,125,"/");
			counter1++;
		  }
	    else          if(((cx>=350)&&(cx<=400))&&((cy>=150)&&(cy<=200)))
		  {
			s[counter]='^';
			outtextxy(175+10*counter1,125,"^");
			counter1++;

		    }
	    else       if(((cx>=150)&&(cx<=200))&&((cy>=200)&&(cy<=250)))
		  {
			s[counter]='4';
			outtextxy(175+10*counter1,125,"4");
			counter1++;
		  }
	    else         if(((cx>=200)&&(cx<=250))&&((cy>=200)&&(cy<=250)))
		  {
			s[counter]='5';
			outtextxy(175+10*counter1,125,"5");
			counter1++;
		  }
	    else         if(((cx>=250)&&(cx<=300))&&((cy>=200)&&(cy<=250)))
		  {
			s[counter]='6';
			outtextxy(175+10*counter1,125,"6");
				counter1++;
		  }
	    else         if(((cx>=300)&&(cx<=350))&&((cy>=200)&&(cy<=250)))
		  {
			s[counter]='s';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"sin(");
			counter1+=4;
		  }
	    else         if(((cx>=350)&&(cx<=400))&&((cy>=200)&&(cy<=250)))
		  {
			s[counter]='x';
			outtextxy(175+10*counter1,125,"x");
			counter1++;
		  }
	    else	if(((cx>=150)&&(cx<=200))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='7';
			outtextxy(175+10*counter1,125,"7");
			counter1++;
		  }
	    else	if(((cx>=200)&&(cx<=250))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='8';
			outtextxy(175+10*counter1,125,"8");
			counter1++;
		  }
	    else	if(((cx>=250)&&(cx<=300))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='9';
			outtextxy(175+10*counter1,125,"9");
				counter1++;
		  }
	    else	if(((cx>=300)&&(cx<=350))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='c';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"cos(");
			counter1+=4;

		  }
	   else	if(((cx>=350)&&(cx<=400))&&((cy>=250)&&(cy<=300)))
		  {
			     counter--;
			     if((counter!=0)&&(counter1!=0))
		  {
				if(
			     ((s[counter]>='0')&&(s[counter]<='9'))
			     ||
			     (s[counter]=='.')
			     ||(s[counter]=='+')
			     ||(s[counter]=='-')
			     ||(s[counter]=='*')
			     ||((s[counter]=='(')&&(isalpha(s[counter-1])==0))
			     ||(s[counter]==')')
			     ||(s[counter]=='/')
			     ||(s[counter]=='^'))
				{
									counter--;

										 counter1-=1;
									 for(int i=175+10*counter1;i<=185+10*counter1;i++)
									 {
										for(int j=125;j<=135;j++)
										{
										putpixel(i,j,BLACK);
										}
									 }
				}
				else if(s[counter]=='x')
				{
								counter--;
									 counter1-=1;
									 for(int i=175+10*counter1;i<=215+10*counter1;i++)
									 {
										for(int j=125;j<=135;j++)
										{
										putpixel(i,j,BLACK);
										}
									 }


				}
			       else	if((s[counter]=='(')&&(s[counter-1]<='z')&&(s[counter-1]>='a'))
				{
									counter-=2;
										 counter1-=4;
									 for(int i=175+10*counter1;i<=215+10*counter1;i++)
									 {
										for(int j=125;j<=135;j++)
										{
										putpixel(i,j,BLACK);
										}
									 }

				}
			  }
		  }
	    else	if(((cx>=150)&&(cx<=200))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='.';
			outtextxy(175+10*counter1,125,".");
			counter1++;
		  }
	    else	if(((cx>=200)&&(cx<=250))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='0';
			outtextxy(175+10*counter1,125,"0");
			counter1++;
		  }
	    else	  if(((cx>=250)&&(cx<=300))&&((cy>=300)&&(cy<=350)))
		  {
			for(int i1=0;i1<640;i1++)
			for(int j1=0;j1<480;j1++)
			putpixel(i1,j1,BLACK);


			s[counter]='=';
			counter--;

		  }
	    else      if(((cx>=300)&&(cx<=350))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='t';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"tan(");
			counter1+=4;
		  }
	    else      if(((cx>=350)&&(cx<=400))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='(';
			outtextxy(175+10*counter1,125,"(");
			counter1++;
		  }
	    else      if(((cx>=150)&&(cx<=200))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='+';
			outtextxy(175+10*counter1,125,"+");
			counter1++;
		  }
	    else      if(((cx>=200)&&(cx<=250))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='-';
			outtextxy(175+10*counter1,125,"-");
			counter1++;
		  }
	    else      if(((cx>=250)&&(cx<=300))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='*';
			outtextxy(175+10*counter1,125,"*");
			counter1++;
		  }
		else      if(((cx>=300)&&(cx<=350))&&((cy>=350)&&(cy<=400)))
		  {
			for(int i=101;i<150;i++)
				for(int j=151;j<400;j++)
					putpixel(j,i,BLACK);
			counter=0;
			counter1=0;
		  }

	    else      if(((cx>=350)&&(cx<=400))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]=')';
			outtextxy(175+10*counter1,125,")");
			counter1++;
		  }
		  counter++;
		  delay(100);
	   }


	   s[counter]=')';
	   s[counter+1]='\0';

   for(int b1=0,p=0,flag=0,flag2=0;((flag==0)&&(s[p]!='\0'));p++)
	   {
		if(p==1){
				if((s[p]=='+')||(s[p]=='*')||(s[p]=='/')||(s[p]=='^')||(s[p]==')'))flag=1;
			}
		switch(s[p])
		{
			case '(':b1++;break;
			case ')':b1--;break;
			case '+':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '*':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '/':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '-':if(((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^'))&&((s[p+1]<'0')||(s[p+1]>'9')))flag=1;break;
		}
	   }
		if(b1!=0)flag=1;
		if((b1!=0)||(flag==1))outtextxy(175+counter1*10,125,"invalid expression");
		else
		{

			for(int q=0;(s[q]!='\0')&&(flag2==0);q++)
			{
				if(s[q]==')')
				{
					int j=q+1;
					if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0'))
					{
						flag2=-300;
					}
				}
				else if(s[q]=='.')
				{
					int j=q+1;
					int ff=-1;
					while((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!='\0')&&(ff==-1))
					{
						if(s[j]=='.')ff=0;
						j++;
					}
					if(ff==0)flag2=-300;
				}


				else if((s[q]=='0')||(s[q]=='x')||(s[q]=='1')||(s[q]=='2')||(s[q]=='3')||(s[q]=='4')||(s[q]=='5')||(s[q]=='6')||(s[q]=='7')||(s[q]=='8')||(s[q]=='9'))
				{

					int j=q+1;
					if((s[j]!='+')&&(s[j]!='x')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0')&&(s[j]!='0')&&(s[j]!='1')&&(s[j]!='2')&&(s[j]!='3')&&(s[j]!='4')&&(s[j]!='5')&&(s[j]!='6')&&(s[j]!='7')&&(s[j]!='8')&&(s[j]!='9')&&(s[j]!='.'))
					{
						flag2=-300;
					}
				}

			/*       else	 if(s[q]=='l')
				{
				   int j=q+1;
					if(s[j]=='(')
					{

						char mn[50];

						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,1000,an);
						if(ans<=0)flag2=-200;

					}
					else if(s[j]=='0')
					{
						flag2=-200;
					}
				}
				else if(s[q]=='/')
				{
					int j=q+1;

					if(s[j]=='(')
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,1000,an);
						if(ans==0)flag2=-200;

					}
					else if((s[j]=='x'))
					{
					flag2=-200;
					}

					else if((s[j]=='0')&&(s[j+1]!='.'))
					{
						flag2=-200;
					}
				}  */




			 }
			if(flag2==(-200))outtextxy(175+(counter1+1)*10,125,"Math Error");
			else if(flag2==(-300))outtextxy(175+(counter1+1)*10,125,"Syntax Error");



			}



	     if((flag==0)&&(flag2==0)) {

			float w[100];
			convert(s,w);
		       /*	cout<<w[0]<<endl<<w[1]<<endl;
			cout<<s<<endl;  */
			graph(s,w);



		      int flag2=1;
		     while(flag2)
		    {    setcolor(WHITE);
			 rectangle(400,100,550,150);
			line(475,100,475,150);
			outtextxy(415,125,"ZOOM IN");
			 outtextxy(490,125,"ZOOM OUT");
			rectangle(525,150,625,200);
			outtextxy(550,175,"Exit");
			ob.get_status();
			if((cx>=550)&&(cx<=625)&&(cy>=150)&&(cy<=200))
			{   	 flag2=0;
			}
			if((cx>=400)&&(cx<=475)&&(cy>=100)&&(cy<=150))
			{
				if(scale<=4)
				{
				scale=scale*2;

				for(int i1=0;i1<640;i1++)
					for(int j1=0;j1<480;j1++)
					putpixel(i1,j1,BLACK);
				setcolor(WHITE);
				graph(s,w);

				}
			else
				{
				flag2=0;
				outtextxy(100,150,"NO MORE ZOOM");
				}
		     }
	      else	if((cx>=475)&&(cx<=550)&&(cy>=100)&&(cy<=150))
		     {
			if(scale>=0.5)
			{
			scale=scale/2;

			for(int i1=0;i1<640;i1++)
				for(int j1=0;j1<480;j1++)
					putpixel(i1,j1,BLACK);
			setcolor(WHITE);
			graph(s,w);

			 }
			else{
			   flag2=0;
			 outtextxy(100,150,"NO MORE ZOOM");
				}

		      }

		   }


	}
	 scale=1;

	setcolor(WHITE);


}
void calc1()
{



	for(int i1=0;i1<640;i1++)
		for(int j1=0;j1<480;j1++)
			putpixel(i1,j1,BLACK);


	int x=150;
	 int y=150;
	 for(int i=0;i<=5;i++)
	 {
		line(x,150,x,400);
		line(150,y,400,y);
		x+=50;
		y+=50;
	 }
	 rectangle(150,100,400,150);
	 outtextxy(175,175,"1");
	 outtextxy(225,175,"2");
	 outtextxy(275,175,"3");
	 outtextxy(325,175,"/");
	 outtextxy(360,175,"Power");
	 outtextxy(175,225,"4");
	 outtextxy(225,225,"5");
	 outtextxy(275,225,"6");
	 outtextxy(325,225,"Sin");
	 outtextxy(375,225,"Log");
	 outtextxy(175,275,"7");
	 outtextxy(225,275,"8");
	 outtextxy(275,275,"9");
	 outtextxy(325,275,"Cos");
	 outtextxy(351,275,"Delete");
	 outtextxy(175,325,".");
	 outtextxy(225,325,"0");
	 outtextxy(275,325,"=");
	 outtextxy(325,325,"Tan");
	 outtextxy(351,325,"(");
	 outtextxy(175,375,"+");
	 outtextxy(225,375,"-");
	 outtextxy(275,375,"*");
	 outtextxy(275,375,"");
	 outtextxy(310,375,"clear");
	 outtextxy(351,375,")");
	 rectangle(500,250,550,300);
	 outtextxy(510,275,"exit");
	     /*Make sure useless user enters properly*/

	 char s[400];
	 int counter=0,counter1=0;
	 s[counter]='(';
	 counter=1;
	 void mscreen();
	 ob.show_mouse();
	 int aas=1;


	 while(aas)
	 {
		while((s[counter]!='=')&&(aas!=0))
			{
			ob.get_status();
			if((cx>500)&&(cx<550)&&(cy>250)&&(cy<300))
			{
				  aas=0;


			}
			else	if(((cx>=150)&&(cx<=200))&&((cy>=150)&&(cy<=200)))
			{
			s[counter]='1';
			outtextxy(175+10*counter1,125,"1");
			counter1++;
			}

			else	  if(((cx>=200)&&(cx<=250))&&((cy>=150)&&(cy<=200)))
			{
			s[counter]='2';
			outtextxy(175+10*counter1,125,"2");
				counter1++;
			}
			else	  if(((cx>=250)&&(cx<=300))&&((cy>=150)&&(cy<=200)))
			{
			s[counter]='3';
			outtextxy(175+10*counter1,125,"3");
				counter1++;
			}
			else	if(((cx>=300)&&(cx<=350))&&((cy>=150)&&(cy<=200)))
			{
			s[counter]='/';
			outtextxy(175+10*counter1,125,"/");
			counter1++;
			}
			else          if(((cx>=350)&&(cx<=400))&&((cy>=150)&&(cy<=200)))
			{
			s[counter]='^';
			outtextxy(175+10*counter1,125,"^");
			counter1++;

			}
			else       if(((cx>=150)&&(cx<=200))&&((cy>=200)&&(cy<=250)))
			{
			s[counter]='4';
			outtextxy(175+10*counter1,125,"4");
			counter1++;
			}
			else         if(((cx>=200)&&(cx<=250))&&((cy>=200)&&(cy<=250)))
			{
			s[counter]='5';
			outtextxy(175+10*counter1,125,"5");
			counter1++;
			}
			else         if(((cx>=250)&&(cx<=300))&&((cy>=200)&&(cy<=250)))
			{
			s[counter]='6';
			outtextxy(175+10*counter1,125,"6");
				counter1++;
			}
			else         if(((cx>=300)&&(cx<=350))&&((cy>=200)&&(cy<=250)))
			{
			s[counter]='s';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"sin(");
			counter1+=4;
			}
			else         if(((cx>=350)&&(cx<=400))&&((cy>=200)&&(cy<=250)))
			{
			s[counter]='l';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"log(");
			counter1+=4;
			}
			else	if(((cx>=150)&&(cx<=200))&&((cy>=250)&&(cy<=300)))
			{
			s[counter]='7';
			outtextxy(175+10*counter1,125,"7");
			counter1++;
			}
			else	if(((cx>=200)&&(cx<=250))&&((cy>=250)&&(cy<=300)))
			{
			s[counter]='8';
			outtextxy(175+10*counter1,125,"8");
			counter1++;
			}
		else	if(((cx>=250)&&(cx<=300))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='9';
			outtextxy(175+10*counter1,125,"9");
				counter1++;
		  }
	    else	if(((cx>=300)&&(cx<=350))&&((cy>=250)&&(cy<=300)))
		  {
			s[counter]='c';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"cos(");
			counter1+=4;

		  }
	   else	if(((cx>=350)&&(cx<=400))&&((cy>=250)&&(cy<=300)))
		  {

			     counter--;
			     if((counter!=0)&&(counter1!=0))
			  {
			     if (    ((s[counter]>='0')&&(s[counter]<='9'))||(s[counter]=='.')
			     ||(s[counter]=='+')
			     ||(s[counter]=='-')
			     ||(s[counter]=='*')
			     ||((s[counter]=='(')&&(isalpha(s[counter-1])==0))
			     ||(s[counter]==')')
			     ||(s[counter]=='/')
			     ||(s[counter]=='^'))
				{
									counter--;

										 counter1-=1;
									 for(int i=175+10*counter1;i<=185+10*counter1;i++)
									 {
										for(int j=125;j<=135;j++)
										{
										putpixel(i,j,BLACK);
										}
									 }
									 }
			       else	if((s[counter]=='(')&&(s[counter-1]<='z')&&(s[counter-1]>='a'))
				{
									counter-=2;
										 counter1-=4;
									 for(int i=175+10*counter1;i<=215+10*counter1;i++)
									 {
										for(int j=125;j<=135;j++)
										{
										putpixel(i,j,BLACK);
										}
									 }

					}
			      }
			      }
	    else	if(((cx>=150)&&(cx<=200))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='.';
			outtextxy(175+10*counter1,125,".");
			counter1++;
		  }
	    else	if(((cx>=200)&&(cx<=250))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='0';
			outtextxy(175+10*counter1,125,"0");
			counter1++;
		  }
	    else	  if(((cx>=250)&&(cx<=300))&&((cy>=300)&&(cy<=350)))
		  {
		       if(counter!=1)
		       {
			s[counter]='=';
			counter--;
			}




		  }
	    else      if(((cx>=300)&&(cx<=350))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='t';
			s[++counter]='(';
			outtextxy(175+10*counter1,125,"tan(");
			counter1+=4;
		  }
	    else      if(((cx>=350)&&(cx<=400))&&((cy>=300)&&(cy<=350)))
		  {
			s[counter]='(';
			outtextxy(175+10*counter1,125,"(");
			counter1++;
		  }
	    else      if(((cx>=150)&&(cx<=200))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='+';
			outtextxy(175+10*counter1,125,"+");
			counter1++;
		  }
	    else      if(((cx>=200)&&(cx<=250))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='-';
			outtextxy(175+10*counter1,125,"-");
			counter1++;
		  }
	    else      if(((cx>=250)&&(cx<=300))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]='*';
			outtextxy(175+10*counter1,125,"*");
			counter1++;
		  }
		else      if(((cx>=300)&&(cx<=350))&&((cy>=350)&&(cy<=400)))
		  {
				for(int i=101;i<150;i++)
				for(int j=151;j<400;j++)
					putpixel(j,i,BLACK);
			counter=0;
			counter1=0;
		  }

	    else      if(((cx>=350)&&(cx<=400))&&((cy>=350)&&(cy<=400)))
		  {
			s[counter]=')';
			outtextxy(175+10*counter1,125,")");
			counter1++;
		  }
		  counter++;
		  delay(100);
	   }


      if(aas!=0)
      {
	   s[counter]=')';
	   s[counter+1]='\0';
	   for(int b1=0,p=0,flag=0,flag2=0;((flag==0)&&(s[p]!='\0'));p++)
	   {
		if(p==1){
				if((s[p]=='+')||(s[p]=='*')||(s[p]=='/')||(s[p]=='^')||(s[p]==')'))flag=1;
			}
		switch(s[p])
		{
			case '(':b1++;break;
			case ')':b1--;break;
			case '+':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '*':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '/':if((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^')||(s[p-1]=='('))flag=1;break;
			case '-':if(((s[p-1]=='+')||(s[p-1]=='-')||(s[p-1]=='*')||(s[p-1]=='/')||(s[p-1]=='^'))&&((s[p+1]<'0')||(s[p+1]>'9')))flag=1;break;
		}
	   }
		if(b1!=0)flag=1;
		if((b1!=0)||(flag==1))outtextxy(175+counter1*10,125,"invalid expression");
		else
		{

			for(int q=0;(s[q]!='\0')&&(flag2==0);q++)
			{
				if(s[q]==')')
				{
					int j=q+1;
					if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0'))
					{
						flag2=-300;
					}
				}
				else if(s[q]=='.')
				{
					int j=q+1;
					int ff=-1;
					while((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!='\0')&&(ff==-1))
					{
						if(s[j]=='.')ff=0;
						j++;
					}
					if(ff==0)flag2=-300;
				}


				else if((s[q]=='0')||(s[q]=='1')||(s[q]=='2')||(s[q]=='3')||(s[q]=='4')||(s[q]=='5')||(s[q]=='6')||(s[q]=='7')||(s[q]=='8')||(s[q]=='9'))
				{

					int j=q+1;
					if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[j]!=')')&&(s[j]!='\0')&&(s[j]!='0')&&(s[j]!='1')&&(s[j]!='2')&&(s[j]!='3')&&(s[j]!='4')&&(s[j]!='5')&&(s[j]!='6')&&(s[j]!='7')&&(s[j]!='8')&&(s[j]!='9')&&(s[j]!='.'))
					{
						flag2=-300;
					}
				}
				else if(s[q]=='l')
				{
				   int j=q+1;
					if(s[j]=='(')
					{

						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,2,an);
						if(ans<=0)flag2=-200;

					}
					else if(s[j]=='0')
					{
						flag2=-200;
					}
				}
				else if(s[q]=='/')
				{
					int j=q+1;

					if(s[j]=='(')
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+1)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,2,an);
						if(ans==0)flag2=-200;

					}
					else	if((s[j]=='s')||(s[j]=='c')||(s[j]=='l')||(s[j]=='t'))
					{
						char mn[50];
						int c2=0;
						int tc=1;
						for(;tc!=0;j++,c2++)
						{       if(j==q+2)tc=0;
							if(s[j]=='(')tc++;
							else if(s[j]==')')tc--;
							mn[c2]=s[j];
						}
						mn[c2+1]='\0';
						float an[50];
						convert(mn,an);
						float ans=evaluate(mn,2,an);
						if(ans==0)flag2=-200;

					}
					else if((s[j]=='0')&&(s[j+1]!='.'))
					{
						flag2=-200;
					}
				}
			}
			if(flag2==(-200))outtextxy(175+(counter1+1)*10,125,"Math Error");
			else if(flag2==(-300))outtextxy(175+(counter1+1)*10,125,"Syntax Error");



			}




	if((flag==0)&&(flag2==0))      {

			float w[100];
			convert(s,w);


	    outtextxy(175+counter1*10,125,"=");
	    float aa=evaluate(s,2,w);
	    char qq[100];
	    gcvt(aa,6,qq);
	    outtextxy(175+(counter1+1)*10,125,qq);


	    }

			counter=1;
			counter1=0;
		  ob.get_status();

		     if(((cx>=300)&&(cx<=350))&&((cy>=350)&&(cy<=400)))
		  {
				for(int i=101;i<150;i++)
				for(int j=151;j<400;j++)
					putpixel(j,i,BLACK);
		  }

	       else	  if((cx>500)&&(cx<550)&&(cy>250)&&(cy<300))
		{
			aas=0;
			counter=1;
			counter1=0;
		}

	  }
     }




}
void mscreen()
{

	while(4)
       {



		setcolor(WHITE);
		for(int i1=0;i1<640;i1++)
		for(int j1=0;j1<480;j1++)
			putpixel(i1,j1,BLACK);

	rectangle(200,50,550,200);
	rectangle(200,300,550,450);
	outtextxy(275,125,"Scientific calculator");
	outtextxy(275,375,"Graph calculator");
	rectangle(570,300,620,350);
	outtextxy(580,325,"exit");

	ob.show_mouse();
	ob.get_status();
		if((cx>=200)&&(cx<=350)&&(cy>=50)&&(cy<=200))
			calc1();
		else if((cx>=200)&&(cx<=350)&&(cy>=300)&&(cy<=450))
			calc2();
			else	if((cx>=570)&&(cx<=620)&&(cy>=300)&&(cy<=350))
			exit(0);


	}
}
void main()
{
	int g=VGA,h=2;
	initgraph(&g,&h,"C:\\turbo\\TC\\bgi");

	mscreen();
	getch();


		getch();
	 closegraph();
}

