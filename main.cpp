#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){

    //Prompt the user for a title for data. Output the title.
    string title;
    cout << "Enter a title for the data: " << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;
    cout << endl;

    //Prompt the user for the headers of two columns of a table. Output the headers.
    string col1;
    cout << "Enter the column 1 header: " << endl;
    getline(cin, col1);
    cout << "You entered: " << col1 << endl;
    cout << endl;
    string col2;
    cout << "Enter the column 2 header: " << endl;
    getline(cin, col2);
    cout << "You entered: " << col2 << endl;
    cout << endl;

    bool cont = true;
    string dp;
    vector<string> names;
    vector<int> nums;
    while (cont){
        //Prompt the user for data points. Data points must be in this format: string, int.
        cout << "Enter a data point (-1 to stop input): " << endl;
        getline(cin, dp);
        //check if user entered -1
        if (dp == "-1"){
            cont = false;
            //output data table
            cout << setw(33) << right << title << endl;
            cout << setw(20) << left << col1;
            cout << "|" << setw(23) << right << col2 << endl;
            cout << "--------------------------------------------" << endl;
            for (int i = 0; i < names.size(); i++){
                cout << setw(20) << left << names[i] << "|" << setw(23) << right << nums[i] << endl;
            }
            cout << endl;
            //output data histogram
            for (int i = 0; i < names.size(); i++){
                cout << setw(20) << right << names[i] << " ";
                for (int j = 0; j < nums[i]; j++){
                    cout << '*' ;
                }
                cout << endl;
            }
            break;
        }

        if (dp.find(',') != -1){  //check if string has one comma
            int index1 = dp.find(','); //first appearance of comma
            if (dp.find(',', index1 + 1) != -1){ //check if more than one comma
                cout << "Error: Too many commas in input." << endl;
                continue;
            }
            string dp1 = dp.substr(0,index1); //string portion of datapoint
            int dp2;
            try {
                dp2 = stoi(dp.substr(index1 + 2)); //integer portion of datapoint
            } catch (invalid_argument& e) { //comma not followed by int
                cout << "Error: Comma not followed by an integer." << endl;
                continue;
            }
            //all comma tests are passed
            names.push_back(dp1);
            nums.push_back(dp2);
            cout << "Data string: " << dp1 << endl;
            cout << "Data integer: " << dp2 << endl << endl;

        } else { //no comma
            cout << "Error: No comma in string." << endl;
            continue;
        }
    }
    return 0;
}