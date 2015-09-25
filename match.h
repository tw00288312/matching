#include<iostream>
#include<vector>
#define sizex 6
using std::endl;
using std::cout;
using std::vector;
using std::cin;
class match{
public:
	match(const match& M);
	match(int i=5);
	void RR();
	bool prefer(match& M);
	void output();
	int size();
	int entry(int i) const;
	void edit(int pos, int v);
	int test();
	bool rotation_balance();
	bool isContinuous(int& x); // x:times of changes
	int printSign(); //print sign representation and return # of '+'
private:
	int max;
	int* matching;
};

match* initial(){   //user define the match with size and elements
	int c;
	cout<<"size:";
	cin>>c;
	match* temp = new match(c);
	int i =1,b;
	while(i<=c && cin>>b){
		temp->edit(i,b);
		i++;
	}
	return temp;

}

match::match(const match& M){ max=sizex; matching = new int[sizex]; for(int i=0;i<max;i++) matching[i] = M.entry(i+1);}
match::match(int i):max(i){matching = new int[i];};

int match::size(){return max;};

int match::entry(int i) const {if(i<=max) return matching[i-1];};

bool match::prefer(match& M){
	int counter=0;
	for(int i=0;i<max;i++){
		for(int j=i+1;j>=1;j--){
			if(matching[i] == M.entry(j) && (j-1) == i)
				break ;
			else if (matching[i] == M.entry(j)){
				counter--;
				break;
				}
			if(j==1) counter++;
		}
	
	}
	return counter>0;
};
void match::edit(int pos,int v){
	matching[pos-1] = v;
}
void match::output(){
	for(int i=0;i<max;i++)
		std::cout<<matching[i]<<" ";
	std::cout<<std::endl;
}

void match::RR(){
	int temp = this->entry(this->size());
	for(int i=this->size();i>1;i--)
		this->edit(i,this->entry(i-1));
		this->edit(1,temp);

	

}
int match::test(){    // test if a match is rotation balance 
	int c =0; // counter for balance
	match m(this->size());
	for (int i=1;i<=this->size();i++)
		m.edit(i,i);
	
	for(int i=0;i<this->size();i++){
		this->output();
		if(this->prefer(m)){
			cout<<"   + ";
			c++;

		}
		else if(m.prefer(*this)){
			cout<<"   - ";
			c--;
		}
		else cout<<"   = ";
		cout<<endl;
	this->RR();
	}
	
return c;
}

bool match::rotation_balance(){
	int c =0; // counter for balance
	match m(this->size());
	for (int i=1;i<=this->size();i++)
		m.edit(i,i);
	
	for(int i=0;i<this->size();i++){
		if(this->prefer(m))	c++;
		else if(m.prefer(*this))	c--;
	this->RR();
	}
return c==0;
}

bool match::isContinuous(int& x){
	bool sign, door=false,posLock=false;
	int c =0; // counter for balance
	int cl=0,max_cl=0; //critical length
	int fl=0; //first length
	match m(this->size());
	for (int i=1;i<=this->size();i++)
		m.edit(i,i);
	
	for(int i=0;i<this->size();i++){
		if(this->prefer(m)){
			posLock=true;
			cl=0;
			if(door==false) {door = true; sign = true;}
			else if(sign==false){ c++; sign = true;} // last symbol is '-'
		}
		else if(m.prefer(*this)){
			if(!posLock) fl++;
			cl++;
			if(door == false) {door = true; sign = false;}
			else if (sign == true) {c++; sign = false;} //last symbol is '+'

		}
		else {cl++;
			if(!posLock) fl++;}
		if(max_cl<cl) max_cl = cl;
		
	this->RR();
	}
if(max_cl<cl+fl) max_cl = cl+fl;
x=max_cl;
return c<3;

}

int match::printSign(){
	int c=0;
	match m(this->size());
	for (int i=1;i<=this->size();i++)
		m.edit(i,i);
	
	for(int i=0;i<this->size();i++){
		if(this->prefer(m)) {cout<< "+ "; c++;}
		else if(m.prefer(*this)) cout<< "- ";
		else cout<< "= ";
	this->RR();
	}
cout<<endl;
	
return c;


}
#if 0
int main(){
	vector<match> V;
	int cc=0,maxx=0;
	match m(sizex),n(sizex),s(sizex),p(sizex);
	for(int i=1;i<=sizex;i++){
		m.edit(i,i);
		n.edit(i,(i+1)%sizex+1);
		p.edit(i,(i+3)%sizex+1);
		s.edit(i,i);
	}
	match* M=initial();
	
	M->test();

  //	for(int a=1;a<=sizex;a++){
  //	for(int b=1;b<=sizex;b++){
  //	for(int c=1;c<=sizex;c++){
  //	for(int d=1;d<=sizex;d++){
  //	for(int e=1;e<=sizex;e++){
  //	for(int f=1;f<=sizex;f++){
//	for(int g=1;g<=sizex;g++){
  //		if(b == a) continue;
  //		if(c == a || c == b) continue;
  // 		if(d == a || d == b || d == c) continue;
  //		if(e == a || e == b || e == c || e == d) continue;
  //		if(f == a || f == b || f == c || f == d || f == e) continue;
//		if(g == a || g == b || g == c || g == d || g == e || g == f) continue;
		
  //		s.edit(1,a);
  //		s.edit(2,b);
  //		s.edit(3,c);
  //		s.edit(4,d);
  //		s.edit(5,e);
  //		s.edit(6,f);
//		s.edit(7,g);
  //		if(s.prefer(m) && s.prefer(n)) {cc++; s.output(); }
  //	}
  //	}	
//	}
  //	}
  //	}
  //	}
  //	}
/*	
	for(int i =0;i<V.size();i++){
		int c=0;
		for(int j=0;j<V.size();j++)
			if(V[i].prefer(V[j])) c++;
		if(maxx<=c) {maxx = c; cout<<"                "; V[i].output();}
		cout<<c<<endl;


	}

	cout<<"max is "<<maxx<<endl;	
*/	std::cout<<cc<<std::endl;
	return 0;

}
#endif
