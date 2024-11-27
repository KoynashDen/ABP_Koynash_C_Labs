//
// Created by Denys on 27.11.2024.
//

#include "MK2.h"

//1
// #include <iostream>
// #include <cmath>
// using namespace std;
// bool collinearity(int x1, int y1, int x2, int y2)
// {
//     if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0)){
//
//         return true;
//
//
//     }else if((x2!=0 && y2!=0) && (fabs(x1)>=fabs(x2))){
//         if(x1/x2 == y1/y2){
//             return true;
//         }
//     }else if(x1!=0 && y1!=0 && (fabs(x1)<=fabs(x2))){
//         if(x2/x1 == y2/y1){
//             return true;
//         }
//     }else if(x1 == 0 && x2 == 0){
//         return true;
//     }else if(y1 == 0 && y2 == 0){
//         return true;
//     }
//
//
//     return false;
// }


// 2
// #include <vector>
// #include <iostream>
// using namespace std;
// bool possibly_perfect(const std::vector<char>& key, const std::vector<char>& answers){
//     int count = 0;
//     int countP = 0;
//     if (key.size() == answers.size()){
//         for(int i = 0; i < int(key.size()); i++){
//             if( key[i] != answers[i] && string(1,key[i])!="_"){
//                 count++;
//             }else if(string(1,key[i])=="_"){
//                 countP++;
//             }
//         }
//         if (count == 0 || count+countP == int(answers.size())){
//             return true;
//         }
//     }
//     return false;
// }
