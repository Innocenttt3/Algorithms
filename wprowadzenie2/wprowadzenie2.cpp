#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(const pair<string, long int>& a, const pair<string, long int>& b){
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
};

int main(){

    int n;
    long int mileage;
    long double p, d;
    string tmpCar;


    cin >> n;
    cin.ignore();
    vector <pair<string, long int> > vec(3);
    for(int i = 0; i < n; i++) {
        getline(cin, tmpCar);
        scanf("%Lf %Lf", &p, &d);
        cin.ignore();
        mileage = ((p * 1000)/ (d  * 0.0254 * 3.141593));
        if(i < 3){
            vec[i] = make_pair(tmpCar, mileage);
        }
        else {
            sort(vec.begin(), vec.end(), comparator);
            if(vec[2].second > mileage ){
                vec[2] = make_pair(tmpCar, mileage);
            }
            else if(vec[2].second == mileage && vec[2].first > tmpCar) {
                vec[2] = make_pair(tmpCar, mileage);
            }
        }
    }
    sort(vec.begin(), vec.end(), comparator);
    int counter = 0;
    for (const auto& pair : vec) {
        if (counter < 3) {
            cout << pair.first << '\n';
            cout << pair.second << '\n';
            counter++;
        } else {
            break;
        }
    }
    return 0;

}