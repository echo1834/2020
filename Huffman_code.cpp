#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 100      //����ַ��������鳤��
#define MAXWEIGHT 10000 //���Ȩֵ
#define MAXHUFF 100     //���������ڵ�ṹ���������
#define MAXCODE 100     //������������ṹ������ĸ���

typedef struct Huffman{
    int weight;      
    char ch;         
    int parent;      
    int leftchild; 
    int rightchild;  
}HuffmanNode;
typedef struct Code{
    int code[MAXNUM];    //�ַ��Ĺ���������Ĵ洢
    int start;           
}HuffmanCode;

HuffmanNode huffman[MAXHUFF];
HuffmanCode code[MAXCODE];

void buildHuffmanTree(int n){
    for (int i=0; i<n*2-1; ++i) {//��ʼ��
        huffman[i].weight=0;
        huffman[i].parent=-1;
        huffman[i].leftchild=-1;
        huffman[i].rightchild=-1;
    }
    for (int i=0; i<n; i++) {
        printf("��ֱ������%d���������ַ���Ȩ��",i);
        std::cin >> huffman[i].ch;
        scanf("%d",&huffman[i].weight);
    }
    int x1,x2,w1,w2;
    for (int i=0; i<n-1; i++) {
        x1=x2=-1;
        w1=w2=MAXWEIGHT;
        for (int j=0; j<n+i; j++) {
            if (huffman[j].parent==-1&&huffman[j].weight<w1) {
                w2=w1;//���ÿ����С�ĸ����ˣ���ô��Ҫ���ϴ���С�ĸ��ڶ�С��
                x2=x1;
                x1=j;
                w1=huffman[j].weight;
            }
            else if (huffman[j].parent==-1&&huffman[j].weight<w2){
                x2=j;
                w2=huffman[j].weight;
            }
        }
        //�ҵ���С�������ڵ��Ҫ�ǵúϲ���һ���µĽڵ�
        huffman[n+i].leftchild=x1;
        huffman[n+i].rightchild=x2;
        huffman[n+i].weight=w1+w2;
        huffman[x1].parent=n+i;
        huffman[x2].parent=n+i;
    }
}
void Print(int n){
    HuffmanCode hcode;   //���浱ǰҶ�ӽڵ���ַ�����
    int curParent;       //��ǰ���ڵ�
    int c;               //�±��Ҷ�ӽڵ�ı��
    for (int i = 0; i < n; ++i){
        hcode.start = n - 1;
        c = i;
        curParent = huffman[i].parent;
        while (curParent != -1){//�������õ����ڵ㣬Ȼ���ж���ڵ��Ƿ�Ϊ��ǰֵ�������ȡ�ڵ�0,����ȡ�ڵ�1
            if (huffman[curParent].leftchild == c){
                hcode.code[hcode.start] = 0;
                //std::cout << "hcode.code[" << hcode.start << "] = 0" << std::endl;
            }
            else{
                hcode.code[hcode.start] = 1;
                //std::cout << "hcode.code[" << hcode.start << "] = 1" << std::endl;
            }
            hcode.start--;
            c = curParent;
            curParent = huffman[c].parent;
        }
        //�ѵ�ǰ��Ҷ�ӽڵ���Ϣ���浽����ṹ������
        for (int j = hcode.start + 1; j < n; j++){
            code[i].code[j] = hcode.code[j];
        }
        code[i].start = hcode.start;
    }
}
int main() {
    printf("�������ж��ٸ��������ַ�");
    int n=0;
    scanf("%d",&n);
    if (n==0) {
        exit(0);
    }
    buildHuffmanTree(n);
    Print(n);
    for (int i = 0; i < n; ++i){
        printf("%c 's Huffman Code is:",huffman[i].ch);
        for (int j = code[i].start + 1; j < n; ++j){
            printf("%d",code[i].code[j]);
        }
        printf("\n");
    }
    return 0;
}
