#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordleHelper(
    const std::string& pattern,
    std::string& cur,
    size_t idx,
    std::string floatingLeft,
    const std::set<std::string>& dict,
    std::set<std::string>& results     
);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
  std::set<std::string> results;
  if(in.empty()) {
      return results;
  }
  std::string cur=in;
  
  wordleHelper(in, cur, 0, floating, dict, results);
  return results;
}

// Define any helper functions here
void wordleHelper(
    const std::string& pattern,
    std::string& cur,
    size_t idx,
    std::string floatingLeft,
    const std::set<std::string>& dict,
    std::set<std::string>& results)
{
  size_t n = cur.size();

  size_t emptySlots = 0;
  for(size_t i = idx; i < n; ++i){
    if(cur[i] == '-') {
        emptySlots++;
    }
  } 
    
  if(floatingLeft.size()>emptySlots){
    return;
  }

  if(idx==n){
    if(floatingLeft.empty() && dict.find(cur) != dict.end()){
      results.insert(cur);
    }
    return;
  }

  if(pattern[idx] != '-'){
    wordleHelper(pattern, cur, idx + 1, floatingLeft, dict, results);
  }else{
    for(char ch = 'a'; ch<='z'; ++ch){
        cur[idx] = ch;

        std::string nextFloating=floatingLeft;
        size_t pos =nextFloating.find(ch);
        if(pos != std::string::npos){
          nextFloating.erase(pos,1);
        }

        wordleHelper(pattern, cur, idx + 1, nextFloating, dict, results);
      }
    cur[idx] = '-';
  }



  // char p = pattern[idx];

  // if(p!= '-'){
  //   cur[idx]= p;

  //   size_t pos = floatingLeft.find(p);
  //   if(pos != std::string::npos){
  //     std::string nextFloating = floatingLeft;
  //     nextFloating.erase(pos,1);
  //     wordleHelper(pattern,cur,idx+1,nextFloating,dict,results);
  //   }else{
  //     wordleHelper(pattern,cur,idx+1,floatingLeft,dict,results);
  //   }
  // }else{
  //   if(floatingLeft.size() == emptySlots){
  //     for(size_t i = 0; i < floatingLeft.size(); i++){
  //       char ch = floatingLeft[i];
  //       cur[idx] = ch;

  //       std:: string nextFloating = floatingLeft;
  //       nextFloating.erase(i,1);

  //       wordleHelper(pattern, cur, idx + 1, nextFloating, dict, results);
  //     }
  //   }
  //   else{
  //     for(char ch = 'a'; ch<='z'; ++ch){
  //       cur[idx] = ch;

  //       std::string nextFloating=floatingLeft;
  //       size_t pos =nextFloating.find(ch);
  //       if(pos != std::string::npos){
  //         nextFloating.erase(pos,1);
  //       }

  //       wordleHelper(pattern, cur, idx + 1, nextFloating, dict, results);
  //     }
  //   }
  // }

}