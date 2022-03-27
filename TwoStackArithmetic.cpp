/*
//FileName: TwoStackArithmetic.cpp
//FileType: Source File
//Author: Kevin Chau
//Created: 03/24/2022
//Last Modified: 03/27/2022 4:05PM
//Description: Using Two Stacks to perform Arithmetic Operations
*/

#include <iostream>
#include <stack>

template <class T>
void printStack(std::stack<T> Stack)
{
  while (!Stack.empty())
  {
    std::cout << Stack.top() << " ";
    Stack.pop();
  }
}

template <class T>
void reverseStack(std::stack<T>& Stack)
{
  T item;
  std::stack<T> TempStack;

  while (!Stack.empty())
  {
    item = Stack.top();
    Stack.pop();
    TempStack.push(item);
  }
  Stack = TempStack;
  return;
}

int compute(char Operator, int value1, int value2)
{
  if (Operator == '+')
  {
    return value1 + value2;
  }
  else if (Operator == '-')
  {
    return value1 - value2;
  }
  else if (Operator == '*')
  {
    return value1 * value2;
  }
  else
  {
    return value1 / value2;
  }
}

void Evaluate(char& input)
{
  std::stack<int> NumStack; 
  std::stack<char> OperatorStack;
  char PreviousOperator = 'x';
  bool PreviousisOperator = false;
  bool multiply = false; 
  int input_number;
  int value1 = 0;
  int value2 = 0;
  char Operator = 'x';

  while (input != '\n')
  {
    if (input == '-' && NumStack.empty() ) 
    {
      NumStack.push(-1);
      OperatorStack.push('*');
      input = std::cin.get();
      input = std::cin.peek();
    }
    if (input == '(')
    {
      OperatorStack.push(input);
      input = std::cin.get();
      input = std::cin.peek();
      if (input == '-')
      {
        std::cin >> input_number;
        input = std::cin.peek();
        NumStack.push(input_number);
        PreviousisOperator = true;
      }
      while (input != ')')
      {
        if (isdigit(input))
        {
          PreviousisOperator = false;
          std::cin >> input_number; 
          NumStack.push(input_number); 
          input = std::cin.peek(); 
        }
        else if (OperatorStack.top() == '*' || OperatorStack.top() == '/')
        {
          if (isdigit(input))
          {
            std::cin >> input_number;
            NumStack.push(input_number);
            Operator = OperatorStack.top(); OperatorStack.pop();
            value1 = NumStack.top(); NumStack.pop();
            value2 = NumStack.top(); NumStack.pop();
            NumStack.push(compute(Operator, value2, value1));
            input = std::cin.peek();
          }
          else if (input == '-')
          {
            std::cin >> input_number;
            input = std::cin.peek();
            NumStack.push(input_number);
            PreviousisOperator = true;
          }
        }
        else if ((PreviousOperator == '-' && input == '-') && PreviousisOperator == true)
        {
          OperatorStack.pop();
          OperatorStack.push('+');
          PreviousOperator = '+';
          PreviousisOperator = true;
          input = std::cin.get();
          input = std::cin.peek();
        }
        else if (((PreviousOperator == '-' && input == '+') && PreviousisOperator == true) || ((PreviousOperator == '+' && input == '-') && PreviousisOperator == true))
        {
          OperatorStack.pop();
          OperatorStack.push('-');
          PreviousOperator = '-';
          PreviousisOperator = true;
          input = std::cin.get();
          input = std::cin.peek();
        }
        else if (input == '+' || input == '-' || input == '*' || input == '/')
        {
          OperatorStack.push(input);
          PreviousisOperator = true;
          PreviousOperator = input;
          input = std::cin.get();
          input = std::cin.peek();
        }
      }
      if (OperatorStack.size() != 0)
      {
        while (OperatorStack.top() != '(')
        {
          Operator = OperatorStack.top(); OperatorStack.pop();
          value1 = NumStack.top(); NumStack.pop();
          value2 = NumStack.top(); NumStack.pop();
          NumStack.push(compute(Operator, value2, value1));
        }
      }
    }
    if ((!OperatorStack.empty() && ( (OperatorStack.top() == '*' || OperatorStack.top() == '/') || OperatorStack.top() == '(') && NumStack.size() >= 1))
    {
      if (OperatorStack.top() == '(')
      {
        OperatorStack.pop();
      }
      if (NumStack.size() >= 2)
      {
        Operator = OperatorStack.top(); OperatorStack.pop();
        value1 = NumStack.top(); NumStack.pop();
        value2 = NumStack.top(); NumStack.pop();
        NumStack.push(compute(Operator, value2, value1));
      }
      else if (isdigit(input))
      {
        std::cin >> input_number; NumStack.push(input_number); 
        Operator = OperatorStack.top(); OperatorStack.pop();
        value1 = NumStack.top(); NumStack.pop();
        value2 = NumStack.top(); NumStack.pop();
        NumStack.push(compute(Operator, value2, value1));
        input = std::cin.peek();
      }
      else if (input == '-')
      {
        NumStack.push(-1);
        OperatorStack.push('*');
        input = std::cin.get();
        input = std::cin.peek();
      }
      else if (input == '(')
      {
        OperatorStack.push(input);
      }
      else 
      {
        input = std::cin.get();
        input = std::cin.peek(); 
      }
    }
    else if (isdigit(input))
    {
      PreviousisOperator = false;
      std::cin >> input_number;
      NumStack.push(input_number);
      input = std::cin.peek();
    }
    else if ((PreviousOperator == '-' && input == '-') && PreviousisOperator == true )
    {
      OperatorStack.pop();
      OperatorStack.push('+');
      PreviousOperator = '+';
      PreviousisOperator = true;
      input = std::cin.get();
      input = std::cin.peek();
    }
    else if (((PreviousOperator == '-' && input == '+') && PreviousisOperator == true) || ((PreviousOperator == '+' && input == '-') && PreviousisOperator == true))
    {
    OperatorStack.pop();
    OperatorStack.push('-');
    PreviousOperator = '-';
    PreviousisOperator = true;
    input = std::cin.get(); 
    input = std::cin.peek();
    }
    else if (input == '+' || input == '-' || input == '*' || input == '/')
    {
      
      PreviousOperator = input; PreviousisOperator = true; OperatorStack.push(input);
      input = std::cin.get();
      input = std::cin.peek();
      if (PreviousOperator == '-' && input == '(')
      {
        OperatorStack.pop();
        NumStack.push(-1);
        OperatorStack.push('*');
        OperatorStack.push('(');
        PreviousOperator = '('; PreviousisOperator = false;
      }
      else if (PreviousOperator == '*' || PreviousOperator == '/')
      {
        if (input == '-' ) 
        {
          NumStack.push(1);
          OperatorStack.push('*');
          value1 = NumStack.top(); NumStack.pop();
          value2 = NumStack.top(); NumStack.pop();
          Operator = OperatorStack.top(); OperatorStack.pop();
          NumStack.push(compute(Operator, value1, value2));
        }
        else if (isdigit(input))
        {
          PreviousisOperator = false;
          std::cin >> input_number;
          NumStack.push(input_number);
          input = std::cin.peek();
          Operator = OperatorStack.top(); OperatorStack.pop();
          value1 = NumStack.top(); NumStack.pop();
          value2 = NumStack.top(); NumStack.pop();
          NumStack.push(compute(Operator, value2, value1));
        }
      }
      else if ( (PreviousOperator == '*' || PreviousOperator =='/') && (input == '('))
      {
        OperatorStack.push('(');
        PreviousOperator = '('; PreviousisOperator = false;
      }
      else
      {
      }
    }
    else
    {
      std::cin.ignore();
      input = std::cin.peek();
    }
  }
  std::cout << "\n\nBoth Stacks before the final Computation\n";
  std::cout << "\nNumber Stack: "; printStack(NumStack);
  std::cout << "\nOperator Stack: "; printStack(OperatorStack);
  while (!OperatorStack.empty() && NumStack.size() > 1)
  {
    if (OperatorStack.top() == '(' || OperatorStack.top() == ')')
    {
      OperatorStack.pop();
    }
    else
    {
      Operator = OperatorStack.top(); OperatorStack.pop();
      value1 = NumStack.top(); NumStack.pop();
      value2 = NumStack.top(); NumStack.pop();
      NumStack.push(compute(Operator, value2, value1));
    }
  }
  while ( NumStack.size() > 1)
  {
    Operator = '+';
    value1 = NumStack.top(); NumStack.pop();
    value2 = NumStack.top(); NumStack.pop();
    NumStack.push(compute(Operator, value2, value1));
  }
  std::cout << "\n\nFinal Answer: "; printStack(NumStack); std::cout << "\n";
}

int main()
{
  char input;
  std::cout << "Evaluate this Operation: ";
  input = std::cin.peek();
  Evaluate(input);
}
