#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using std::string; 
#include"Elguindi_Zak_QuickSort.cpp"
#include<fstream>
#include<chrono>
using namespace std::chrono; 



using namespace std; 


void GenerateInputs(char* argv[]) {
  int max = 100; 
  int thisSize = 10; 

  fstream recordTime;
  std::ofstream { "Elguindi_Zak_executionTime.txt"};
  recordTime.open("Elguindi_Zak_executionTime.txt"); 

  recordTime << "Input Size\tExecution Time\n"; 

  fstream recordAvgTime; 
  std::ofstream{"Elguindi_Zak_averageExecutionTime.txt"};
  recordAvgTime.open("Elguindi_Zak_averageExecutionTime.txt"); 
  recordAvgTime << "Input Size\tAverage Execution Time\n";
 

  for(int i=1; i<=3; i++) {
    //run for each size
    double sumOfSize = 0; 
    for(int k=0; k<25; k++) {
      //run 25 times for each size
      int* nums = new int; 
      string inputfilename = to_string(i) +"-"+to_string(k)+"-"+argv[1]; 
      std::ofstream { inputfilename};
  
      fstream inputs;
      inputs.open(inputfilename);  
      for(int j=0; j<(thisSize); j++) {
        //run "size" times for each input size
        int posOrNeg = rand() % 2; 
        if(posOrNeg == 0) {
          posOrNeg--; 
        }
        nums[j] = posOrNeg * (rand() % max); 
        inputs << nums[j] << " "; 
      }

      auto start = high_resolution_clock::now(); 
      Sort(nums, 0, thisSize-1);
      auto end = high_resolution_clock::now(); 

      string outputfilename = to_string(i) +"-"+to_string(k)+"-"+argv[2]; 

      std::ofstream {outputfilename}; 
      fstream output;
      output.open(outputfilename); 
      for(int j=0; j<(thisSize); j++) {
        output << nums[j] << " ";
        if(j % 10 == 9) {
          output << "\n";
        }
      }
    

      auto timeMillis = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

      auto convertedTime = timeMillis/1000.0; 


      recordTime << thisSize << "\t\t\t\t\t" << convertedTime << "\n"; 

      sumOfSize += convertedTime; 

      /**
       * add recordTime to an ongoing number thing, divide whole by 25. 
       * add whole to avgExecutionTime.txt
       * */

      delete nums; 
    }
    sumOfSize = sumOfSize / 25; 
    recordAvgTime << thisSize << "\t\t\t\t\t" << sumOfSize << "\n";
    thisSize *= 10; 
  }

};

int main(int argc, char* argv[]) {
  /**
   * generate input, upload to input.txt --WORKS 
   * sort this current input --WORKS
   * send to output.txt --WORKS
   * append to executiontime.txt --WORKS
   * parse executiontime.txt by input file sizes --WORKS 
   * find average execution times by size, append to avgExecution.txt 
   * 
   * */

  if(argc > 3) {
    cout << "Too many files" << endl; 
  }

  cout << "Generating inputs..." << endl; 
  GenerateInputs(argv); 
  cout << "inputs generated" << endl;
  return 0; 
}; 


