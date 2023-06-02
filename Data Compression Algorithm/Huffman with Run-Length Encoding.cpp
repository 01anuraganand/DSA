//Taken from Data Structures and Algorithms in C++ by Adam Drozdek
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;
void error (string s)
{
  throw runtime_error(s);
}
class HuffmanNode
{
	public:
		char symbol;
		unsigned long codeword, freq;
		unsigned int runLen, codewordLen;
		HuffmanNode *left;
		HuffmanNode *right;
		HuffmanNode(){left = right = 0;}
		HuffmanNode(char s, unsigned long f, unsigned int r, HuffmanNode *lt = 0, HuffmanNode *rt = 0)
		{
			symbol = s; freq = f; runLen = r; left = lt; right = rt;
		}
};

class ListNode
{
	public:
		HuffmanNode *tree;
		ListNode *next, *prev;
		ListNode()
		{
			next = prev = 0;
		}
		ListNode(ListNode *p, ListNode *n)
		{
			prev = p, next = n;
		}
};

class DataRec
{
	public:
		char symbol;
		unsigned int runLen;
		unsigned long freq;
		DataRec() {}
		
		bool operator == (const DataRec &dr) const
		{
			return symbol == dr.symbol && runLen == dr.runLen;
		}
		
		bool operator < (const DataRec &dr) const 
		{
			return freq < dr.freq;
		}
};

class HuffmanCoding
{		
	private:
		const unsigned int bytes, bits, ASCII;
		unsigned int dataSize;
		const unsigned long mask;
		unsigned long charCnt;
		ofstream fout;
		HuffmanNode * HuffmanTree, **chars;
		
		vector<DataRec> data;
		void error(char *s)
		{
			cerr << s <<endl;exit(1);
		}
		void output(unsigned long pack);
		void garnerData(ifstream &);
		void outputFrequencies(ifstream&);
		void read2ByteNum(unsigned int&, ifstream&);
		void read4ByteNum(unsigned long&, ifstream&);
		void inputFrequencies(ifstream&);
		void createHuffmanTree();
		void createCodewords(HuffmanNode *, unsigned long, int);
		void transformTreeToArrayOfLists(HuffmanNode *);
		void encode(ifstream&);
		void decode(ifstream&);
		
	public:
		HuffmanCoding(): mask(0xff), bytes(4), bits(8), ASCII(256)
		{
			chars = new HuffmanNode*[ASCII+1];
		}
		
		void compress(char *, ifstream &);
		void decompress(char *, ifstream &);
};

void HuffmanCoding::output(unsigned long pack)
{
	char *s = new char[bytes];
	for(int i = bytes-1; i>=0; i--)
	{
		s[i] = pack & mask;
		pack >>= bits;
	}
	for(int i = 0; i<bytes; i++)
		fout.put(s[i]);
}

void HuffmanCoding::garnerData(ifstream& fin)
{
	char ch, ch2;
	DataRec r;
	vector<DataRec>::iterator i;
	r.freq = 1;
	for(fin.get(ch); !fin.eof(); ch = ch2)
	{
		for(r.runLen = 1, fin.get(ch2); !fin.eof() && ch2 == ch; r.runLen++)
			fin.get(ch2);
		r.symbol = ch;
		if((i = find(data.begin(), data.end(), r)) == data.end())
			data.push_back(r);
		else
			i->freq++;
	}
	sort(data.begin(), data.end());
}

void HuffmanCoding::outputFrequencies(ifstream& fin)
{
	unsigned long temp4;
	char ch = data.size();
	unsigned int temp2 = data.size();
	temp2 >>= bits;
	fout.put(char(temp2)).put(ch);
	fin.clear();
	output((unsigned long)fin.tellg());
	for(int j = 0; j<data.size(); j++)
	{
		fout.put(data[j].symbol);
		ch = temp2 = data[j].runLen;
		temp2 >>= bits;
		fout.put(char(temp2)).put(ch);
		temp4 = data[j].freq;
		output(temp4);
	}
}

void HuffmanCoding::read2ByteNum(unsigned int& num, ifstream& fin)
{
	num = fin.get();
	num <<= bits;
	num |= fin.get();
}

void HuffmanCoding::read4ByteNum(unsigned long& num, ifstream& fin)
{
	num = (unsigned long) fin.get();
	for(int i = 1; i<4; i++)
	{
		num <<= bits;
		num |= (unsigned long) fin.get();
		
	}
}

void HuffmanCoding::inputFrequencies(ifstream& fin)
{
	DataRec r;
	read2ByteNum(dataSize, fin);
	read4ByteNum(charCnt, fin);
	data.reserve(dataSize);
	for(int j = 0; !fin.eof() && j < dataSize; j++)
	{
		r.symbol = fin.get();
		read2ByteNum(r.runLen, fin);
		read4ByteNum(r.freq, fin);
		data.push_back(r);
	}
}

void HuffmanCoding::createHuffmanTree()
{
	ListNode *p, *newNode, *head, *tail;
	unsigned long newFreq;
	head = tail = new ListNode;
	head->tree = new HuffmanNode(data[0].symbol, data[0].freq, data[0].runLen);
	for(int i = 1; i<data.size(); i++)
	{
		tail->next = new ListNode(tail, 0);
		tail = tail->next;
		tail->tree = new HuffmanNode(data[i].symbol, data[i].freq, data[i].runLen);
	}
	while(head != tail)
	{
		newFreq = head->tree->freq + head->next->tree->freq;
		for(p = tail; p!= 0 && p->tree->freq > newFreq; p = p->prev);
		newNode = new ListNode(p, p->next);
		p->next = newNode;
		if(p == tail)
			tail = newNode;
		else
			newNode->next->prev = newNode;
		
		newNode->tree = new HuffmanNode('\0', newFreq, 0, head->tree, head->next->tree);
		head = head->next->next;
		delete head->prev->prev;
		delete head->prev;
		head->prev = 0;
	}
	HuffmanTree = head->tree;
	delete head;
}

void HuffmanCoding::createCodewords(HuffmanNode *p, unsigned long codeword, int level)
{
	if(p->left == 0 && p->right == 0)
	{
		p->codeword = codeword;
		p->codewordLen = level;
	}
	else
	{
		createCodewords(p->left, codeword<<1, level+1);
		createCodewords(p->right, (codeword<<1)+1, level+1);
	}
}

void HuffmanCoding::transformTreeToArrayOfLists(HuffmanNode *p)
{
	if(p->left == 0 && p->right == 0)
	{
		p->right = chars[(unsigned char) p->symbol];
		chars[(unsigned char)p->symbol] = p;
	}
	else
	{
		transformTreeToArrayOfLists(p->left);
		transformTreeToArrayOfLists(p->right);
	}
}

void HuffmanCoding::encode(ifstream& fin)
{
	unsigned long packCnt = 0, hold, maxPack = bytes*bits, pack = 0;
	char ch, ch2;
	int bitsLeft, runLength;
	for(fin.get(ch); !fin.eof();)
	{
		for(runLength = 1, fin.get(ch2); !fin.eof() && ch2 == ch; runLength++)
			fin.get(ch2);
		for(HuffmanNode *p = chars[(unsigned char) ch]; p!= 0 && runLength != p->runLen; p = p->right)
			if(p == 0)
				error("A problem in encode()");
			if(p->codewordLen < maxPack - packCnt)
			{
				pack = (pack << p->codewordLen) | p->codeword; 
				packCnt += p->codewordLen;
			}
			else
			{
				bitsLeft = maxPack - packCnt;
				pack <<=bitsLeft;
				if(bitsLeft != p->codewordLen)
				{
					hold = p->codeword;
					hold >>= p->codewordLen - bitsLeft;
					pack |= hold;
				}
				else
					pack |= p->codeword;
				
				output(pack);
				
				if(bitsLeft != p->codewordLen)
				{
					pack = p->codeword;
					packCnt = maxPack - (p->codewordLen - bitsLeft);
					packCnt = p->codewordLen - bitsLeft;
				}
				else
					packCnt = 0;
			}
			ch = ch2;
	}
	if(packCnt != 0)
	{
		pack <<= maxPack - packCnt;
		output(pack);
	}
}

void HuffmanCoding::compress(char *inFileName, ifstream& fin)
{
	char outFileName[30];
	strcpy(outFileName, inFileName);
	if(strchr(outFileName, '.'))
		strcpy(strchr(outFileName , '.')+1, "z");
	else
		strcat(outFileName, ".z");
	
	fout.open(outFileName, ios::out | ios::binary);
	garnerData(fin);
	outputFrequencies(fin);
	createHuffmanTree();
	createCodewords(HuffmanTree, 0, 0);
	for(int i = 0; i<=ASCII, i++)
		chars[i] = 0;
	transformTreeToArrayOfLists(HuffmanTree);
	fin.clear();
	fin.seekg(0, ios::beg);
	encode(fin);
	fin.clear();
	cout.precision(2);
	cout<<"Compression rate = " <<100.0*(fin.tellg() - fout.tellp())/fin.tellg() << "%\n"<<"Compression rate without table = " <<100.0*(fin.tellg() - fout.tellp()+data.size()*(2+4))/fin.tellg();
	fout.close();
}

void HuffmanCoding::decode(ifstream& fin)
{
	unsigned long chars;
	char ch, bitCnt = 1, mask = 1;
	mask <<=bits -1 ;
	for(chars = 0, fin.get(ch); !fin.eof() && chars < charCnt;)
	{
		for(HuffmanNode *p = HUffmanTreee; ; )
		{
			if(p->left == 0 && p->right == 0)
			{
				for(int j = 0; j<p->runLen; j++)
					fout.put(p->symbol);
				chars += p->runLen;
				break;
			}
			else if((ch & mask) == 0)
				p = p->left;
			else
				p = p->right;
			if(bitCnt++ == bits)
			{
				fin.get(ch);
				bitCnt  = 1;
			}
			else
				ch <<= 1;
		}
	}


void HuffmanCoding::decompress(char *inFileName, ifstream& fin)
{
	char outFileName[30];
	strcpy(outFileName, inFileName);
	if(strchr(outFileName, '.'))
		strcpy(strchr(outFileName, '.')+1, "dec");
	else
		strcat(outFileName, ".dec");
	fout.open(outFileName, ios::out | ios::binary);
	inputFrequencies(fin);
	createHuffmanTree();
	createCodewords(HuffmanTree, 0, 0);
	decode(fin);
	fout.close();
}

int main(int argc, char *argv[])
{
	char fileName[30];
	HuffmanCoding Huffman;
	if(argc != 2)
	{
		cout<<"Enter the file name:";
		cin>>fileName;
	}
	else
		strcpy(fileName, argv[1]);
	ifstream fin(fileName, ios::binary);
	if(fin.fail())
	{
		cerr << "Cannot Open "<< fileName <<endl;
		return 0;
	}
	Huffman.decompress(fileName, fin);
	fin.close();
	return 0;
}