#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
void print_args(){
	printf("optind: %d\n", optind);
	printf("optopt: %d\n", optopt);
	printf("optarg: %s\n", optarg);
}

// global optindは所謂loop内のindexではなくargv内での次のindex数であり、
// これはハイフン（-）によって判断される。-aftのように結合されているとoptindは
// [1, 1, 2] となり、-a -f -t だと[2, 3, 4] となる。（初期値=1）
// オプションの順番が関係するプログラムや、パラメータの有無を判断することなどに使える（？）。
// global optopt はエラーprevious のプロセスがエラーだった場合そのstringのintを返す。
// エラーが出ていない場合は0。

int main(int argc, char *argv[]){
	int opt;

	while ((opt = getopt(argc, argv, "af:tx")) != -1) {
		switch (opt) {
		case 'a':
			print_args();
			break;
		case 'f':
			print_args();
			break;
		case 't':
			print_args();
			break;
		case 'x':
			print_args();
			break;
		case '?':
			print_args();
			break;
		}
	}
}
