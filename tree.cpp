#include <iostream>
#include <stdio.h>
// #include <list>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        // int len = secret.size();
        int secretflag[secret.size()];
        int guessflag[secret.size()];

        // find A
        for(int i = 0; i < secret.size(); i++){
            if (secret[i] == guess[i]){
                bull++;
                secretflag[i] = 1;
                guessflag[i] = 1;
            }
        }
        // find B
        for(int i = 0; i < secret.size(); i++){
            // not A
            if (!secretflag[i]){
            	// cout << secret[i]<<endl;
                for(int j = 0; j < guess.size(); j++){
                	cout << "guessflag: " << guessflag[j] << endl;
                    if (!guessflag[j] && (secret[i] == guess[j])){
                    	cout << guess[j]<< "  guess"<<endl;

                        cow++;
                        guessflag[j] = 2;
                        break;
                    }
                }
            }
        }
        // char *a = itoa(bull);
        // string a_str = string(a);
        // a_str += "A";
        // char *b = itoa(cow);
        // string b_str = string(b);
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};

int main(){
	// cout << "hello world" << endl;
	// int a[] = {1,2,3,4};

	// list<int> input (a, a+sizeof(a)/sizeof(int));
	// list<int> ans;
	// // list<int> input (a,a);
	// // for (int i = 0; i < input.size() ; i++){
	// sum = input.
	// for (list<int>::iterator it = input.begin()+1; it != input.end()-1; it++){
	// 	// cout << input(i) << " ";
	// 	// cout << "hi";
	// 	// cout << *it << " ";

	// }

	// cout << endl<<sizeof(a)<<endl;
	Solution s;
	cout << s.getHint("1807", "7810")<< endl;

}
