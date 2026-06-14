#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class treecnode {
public:
	int fr;
	char info;
	string code;
	treecnode* pr, * pl;
};
class listcnode {
public:
	char info;
	int fr;
	listcnode* pnext;
	treecnode* pdown;
	listcnode() {
		fr = 0;
		pnext = NULL;
		pdown = NULL;
	}
};
class codecnode {
public:
	char info;
	codecnode* pnext;
	string code;
};
class clist {

public:
	listcnode* phead;
	listcnode* ptail;

	clist()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist()
	{
		listcnode* ptrav = phead;
		while (phead != NULL)
		{
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(listcnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
			
		}
	}
	void insert(listcnode* pnn) {
		if (phead == NULL) {
			phead = pnn;
		}
		else {
			listcnode* pb = NULL;
			listcnode* ptrav = phead;
			while (ptrav != NULL && ptrav->fr < pnn->fr) {
				pb = ptrav;
				ptrav = ptrav = ptrav->pnext;
			}
			if (pb != NULL) {
				pb->pnext = pnn;
				pnn->pnext = ptrav;
			}
			else {
				phead = pnn;
				pnn->pnext = ptrav;
			}
		}
	}

	listcnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		else
		{
			listcnode* ptrav = phead;
			phead = phead->pnext;
			ptrav->pnext = NULL;
			return ptrav;
		}
	}
};
void dr_ahmed_bad(treecnode* ptrav) {
	if (ptrav == NULL) {
		return;
	}
	dr_ahmed_bad(ptrav->pl);
	if (ptrav->pl == NULL && ptrav->pr == NULL) {
		int i = 0;
		while (ptrav->code[i + 1] != NULL) {
			i++;
		}
		if (ptrav->code[i] == '0') {
			cout << ptrav->info << "," << ptrav->code << endl;
		}
	}
	dr_ahmed_bad(ptrav->pr);
}
class clist2 {

public:
	codecnode* phead;
	codecnode* ptail;

	clist2()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist2()
	{
		codecnode* ptrav = phead;
		while (phead != NULL)
		{
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(codecnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;

		}
	}
	/*void insert(codecnode* pnn) {
		if (phead == NULL) {
			phead = pnn;
		}
		else {
			codecnode* pb = NULL;
			codecnode* ptrav = phead;
			while (ptrav != NULL && ptrav->fr < pnn->fr) {
				pb = ptrav;
				ptrav = ptrav = ptrav->pnext;
			}
			if (pb != NULL) {
				pb->pnext = pnn;
				pnn->pnext = ptrav;
			}
			else {
				phead = pnn;
				pnn->pnext = ptrav;
			}
		}
	}*/

	/*codecnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		else
		{
			codecnode* ptrav = phead;
			phead = phead->pnext;
			ptrav->pnext = NULL;
			return ptrav;
		}
	}*/
};
listcnode *if_counted(clist &l, char x) {
	listcnode* ptrav = l.phead;
	int ctbad = 0;
	while (ptrav != NULL) {
		if (ptrav->info == x) {
			ctbad++;
			break;
		}
		ptrav = ptrav->pnext;
	}
	if (ctbad == 0) {
		return NULL;
	}
	else {
		return ptrav;
	}
}
void disp(clist &l) {
	listcnode* ptrav = l.phead;
	while (ptrav != NULL)
	{
		cout << ptrav->info << "," << ptrav->fr << endl;
		ptrav = ptrav->pnext;
	}
}
void code(treecnode*ptrav,string binary) {
	//cout << ptrav->info << "," << ptrav->fr;
	if (ptrav == NULL) {
		return;
	}
	code(ptrav->pl,binary+"0");
	ptrav->code = binary;
	code(ptrav->pr,binary+"1");
}
void copy(clist2& lm, treecnode* ptrav) {
	codecnode* pnn;
	if (ptrav == NULL) {
		return;
	}
	copy(lm, ptrav->pl);
	if (ptrav->pr == NULL&&ptrav->pl==NULL) {
		pnn = new codecnode();
		pnn->info = ptrav->info;
		pnn->code = ptrav->code;
		lm.attach(pnn);
	}
		copy(lm, ptrav->pr);

}
void dispcode(clist2& lm) {
	codecnode* ptrav = lm.phead;
	while (ptrav != NULL)
	{
		cout << ptrav->info << "," << ptrav->code<< endl;
		ptrav = ptrav->pnext;
	}
}
void dispall(treecnode* ptrav) {
	if (ptrav == NULL) {
		return;
	}
	dispall(ptrav->pl);
	//if (ptrav->pr == NULL&&ptrav->pl==NULL) 
		cout << ptrav->info << "," << ptrav->fr<<endl;
	
	dispall(ptrav->pr);
}
string find_letter(char l, clist2 &lm) {
	codecnode* ptrav = lm.phead;
	while (ptrav != NULL) {
		if (ptrav->info == l) {
			break;
		}
		ptrav = ptrav->pnext;
	}
	return ptrav->code;
}
codecnode* find_letter2(string curcode,clist2&lm) {
	codecnode* ptrav = lm.phead;
	int f = 0;
	while (ptrav != NULL) {
		if (ptrav->code == curcode) {
			f = 1;
			break;
		}
		ptrav = ptrav->pnext;
	}
	if (f == 1) {
		return ptrav;
	}
	else {
		return NULL;
	}
}
void main() {
	ifstream f1("f1.bmp", ifstream::binary);
	ofstream f2("f2.bmp", ofstream::binary);
	char comp,ch;
	 char m2 = 1, m = 0;
	clist l;
	clist2 lm;
	string binary="",bcode,curcode="";
	int ct = 0, i = 0,ebit=0,h;
	listcnode* ptmp, * ptmp2, * pnn;
	treecnode* pnn2, * pnn3, * pnn4=NULL;
	codecnode* ptrav2;
	f1.seekg(0, f1.end);
	h = f1.tellg();
	cout << h<<endl;
	f1.seekg(0, f1.beg);
	for (i = 0;i < h;i++) {
		f1.read(&ch, 1);
	   int i = 0, j, ct = 0;
	     listcnode* pnn;
		listcnode* rs = if_counted(l, ch);
		if (rs == NULL) {
			pnn = new listcnode();
			pnn->info = ch;
			pnn->fr++;
			pnn->pnext = NULL;
			pnn->pdown = NULL;
			l.insert(pnn);
		}
		else {
			rs->fr++;
		}
	}
	//sorting &frq
	//creating tree
	while (l.phead->pnext != NULL) {
		ptmp = l.pop();
		ptmp2 = l.pop();
		pnn = new listcnode();
		pnn->fr = ptmp->fr + ptmp2->fr;
		pnn2 = new treecnode();
		pnn->pdown = pnn2;
		pnn2->fr = pnn->fr;
		pnn2->info = '-';
		pnn->info = '-';
		if (ptmp->pdown == NULL && ptmp2->pdown == NULL) {
			pnn3 = new treecnode();
			pnn4 = new treecnode();
			pnn3->info = ptmp->info;
			pnn3->fr = ptmp->fr;
			pnn3->pl = NULL;
			pnn3->pr = NULL;
			pnn4->info = ptmp2->info;
			pnn4->fr = ptmp2->fr;
			pnn4->pl = NULL;
			pnn4->pr = NULL;
			pnn2->pl = pnn3;
			pnn2->pr = pnn4;
		}
		if (ptmp->pdown == NULL && ptmp2->pdown != NULL) {
			pnn3 = new treecnode();
			pnn3->info = ptmp->info;
			pnn3->fr = ptmp->fr;
			pnn3->pl = NULL;
			pnn3->pr = NULL;
			pnn2->pl = pnn3;
			pnn2->pr = ptmp2->pdown;
		}
		if (ptmp->pdown != NULL && ptmp2->pdown == NULL) {
			pnn4 = new treecnode();
			pnn4->info = ptmp2->info;
			pnn4->fr = ptmp2->fr;
			pnn4->pl = NULL;
			pnn4->pr = NULL;
			pnn2->pl = ptmp->pdown;
			pnn2->pr = pnn4;
		}
		if (ptmp->pdown != NULL && ptmp2->pdown != NULL) {
			pnn2->pl = ptmp->pdown;
			pnn2->pr = ptmp2->pdown;
		}
		l.insert(pnn);
		delete[]ptmp;
		delete[]ptmp2;
	}
	l.phead->info = '-';
	//generate code
	code(l.phead->pdown, binary);
	copy(lm, l.phead->pdown);
	ofstream code("code.txt",ofstream::binary);
	codecnode* pnn5,*ptrav5;
	ptrav5 = lm.phead;
	while (ptrav5 !=NULL)
	{
		code << ptrav5->info << ptrav5->code<<endl;
		ptrav5 = ptrav5->pnext;
	}
	//dispcode(lm);
	//start phase 2
	//compress 
	int  j=0,k=0,a=0;
	//hell0
	f1.seekg(0, f1.beg);
	for (i = 0;i<h;i++) {
		
		f1.read(&ch, 1);
		bcode = find_letter(ch, lm);
		j = 0;
		while (bcode[j]!=NULL) {
			ct++;
			if (bcode[j] == '1') {
				m = m | (m2 << 8 - ct);
			}
			
			if (ct == 8) {
				f2.write(&m, 1);
				ct = 0;
				m = 0;
			}
			j++;
		}
	}
	  if (ct > 0) { 
		 f2.write(&m, 1);
		 ebit = ct;
		  ct = 0;
	  }
	  f2.close();
	//decomp
	m2 = 1;
	a = 0;
	 k = -1;
	char r;
	int flag = 0,ct2=0;
	ifstream f3("f2.bmp", ifstream::binary);
	ofstream f4("f4.bmp", ofstream::binary);
	f3.seekg(0, f3.end);
	h = f3.tellg();
	cout << h << endl;
	f3.seekg(0, f3.beg);
	for (i = 0;i<h;i++) {
		j = 7;
	   f3.read(&ch, 1);
		if (i+1 == h) {
			k = 7-ebit;
		}
		while (j > k) {
			r = ch & m2 << j;
			if (r != 0) {
				curcode += '1';
			}
			else {
				curcode += '0';
			}
			codecnode* temp = find_letter2(curcode,lm);
			if (temp != NULL) {
				cout << temp->info;
				f4.write(&temp->info, 1);
				temp = NULL;
				curcode = "";
			}
			j--;
		}
	}
}
