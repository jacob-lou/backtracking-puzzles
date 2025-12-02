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
  size_t n=pattern.size();
  if(idx==n){
    if(floatingLeft.empty()){
      if(dict.find(cur)!=dict.end()){
        results.insert(cur);
      }
    }
    return;
  }

  size_t remainingSlots = n - idx;
  if(floatingLeft.size()>remainingSlots){
    return;
  }
  char p = pattern[idx];

  if(p!= '-'){
    cur[idx]= p;

    size_t pos = floatingLeft.find(p);
    if(pos != std::string::npos){
      floatingLeft.erase(pos,1);
    }

    wordleHelper(pattern, cur, idx+1,floatingLeft,dict,results);
  }else{
    if(floatingLeft.size() == remainingSlots){
      for(size_t i = 0; i < floatingLeft.size(); ++i){
        char ch = floatingLeft[i];
        cur[idx] = ch;

        std::string newFloating = floatingLeft;
        newFloating.erase(i, 1); 

        wordleHelper(pattern, cur, idx + 1, newFloating, dict, results);
      }
    }
    else{
      for(char ch = 'a'; ch<='z'; ++ch){
        cur[idx] = ch;

        std::string newFloating = floatingLeft;
        size_t pos = newFloating.find(ch);
        if(pos!= std::string::npos){
          newFloating.erase(pos,1);
        }

        size_t remainingSlotsNext = n-(idx+1);

        if(newFloating.size()>remainingSlotsNext){
          continue;
        }

        wordleHelper(pattern, cur, idx+1, newFloating, dict, results);    
      }
    }
  }

}