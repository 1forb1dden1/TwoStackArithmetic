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
  //VALUE1 is the top or right
  //VALUE2 is the bottom or left 
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
      std::cout << "The top of the stack: " << OperatorStack.top();
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
          std::cin >> input_number; // retreives and reads info. 
          NumStack.push(input_number); // inputs the info to numstack.
          input = std::cin.peek(); // input is now looking at the next value. }
        }
        else if (OperatorStack.top() == '*' || OperatorStack.top() == '/')
        {
          //(2*-3)
          //(2*3)
          //
          if (isdigit(input))
          {
            std::cin >> input_number;
            NumStack.push(input_number); // input number into NumStack.
            Operator = OperatorStack.top(); OperatorStack.pop();
            value1 = NumStack.top(); NumStack.pop();
            value2 = NumStack.top(); NumStack.pop();
            NumStack.push(compute(Operator, value2, value1));
            input = std::cin.peek(); // input goes to next one.
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
          std::cout << "in here";
          Operator = OperatorStack.top(); OperatorStack.pop();
          value1 = NumStack.top(); NumStack.pop();
          value2 = NumStack.top(); NumStack.pop();
          NumStack.push(compute(Operator, value2, value1));
        }
        OperatorStack.pop();
      }
    }
    else if ((!OperatorStack.empty() && ( (OperatorStack.top() == '*' || OperatorStack.top() == '/') || OperatorStack.top() == '(') && NumStack.size() >= 1))
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
        std::cin >> input_number;
        NumStack.push(input_number); // input number into NumStack.
        Operator = OperatorStack.top(); OperatorStack.pop();
        value1 = NumStack.top(); NumStack.pop();
        value2 = NumStack.top(); NumStack.pop();
        NumStack.push(compute(Operator, value2, value1));
        input = std::cin.peek(); // input goes to next one.
      }
      else if (input == '-') // if it is negative
      {
        std::cin >> input_number;
        input = std::cin.peek();
        NumStack.push(input_number);
        PreviousisOperator = true;
      }
      else if (input == '(')
      {
        OperatorStack.push(input);
        input = std::cin.get();
        input = std::cin.peek();
      }
      else 
      {
        input = std::cin.get();
        input = std::cin.peek(); // go to next number
      }
    }
    else if (isdigit(input))
    {
      PreviousisOperator = false;
      std::cin >> input_number; // retreives and reads info. 
      NumStack.push(input_number); // inputs the info to numstack.
      input = std::cin.peek(); // input is now looking at the next value.
    }
    else if ((PreviousOperator == '-' && input == '-') && PreviousisOperator == true ) // and if 
    {
      OperatorStack.pop(); //pop the previous minus sign.
      OperatorStack.push('+'); // input the plus sign.
      PreviousOperator = '+';
      PreviousisOperator = true;
      input = std::cin.get(); // retreives the current input and goes next.
      input = std::cin.peek(); // input is now peeking at the next one.
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
      input = std::cin.get(); // input reads and goes next
      input = std::cin.peek(); // input is now next. 
      if (PreviousOperator == '-' && input == '(')
      {
        OperatorStack.pop();
        NumStack.push(-1);
        OperatorStack.push('*');
        OperatorStack.push('(');
        PreviousOperator = '('; PreviousisOperator = false;
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
      std::cin.ignore(); // ignore the current value 
      input = std::cin.peek(); // goes next. 
    }
  }

  std::cout << "\n\nThis is post Loop before Computation\n";
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
      value1 = NumStack.top(); NumStack.pop(); // top 
      value2 = NumStack.top(); NumStack.pop(); // bottom 
      NumStack.push(compute(Operator, value2, value1));
    }
  }

  //while ( NumStack.size() > 1)
  //{
  //  Operator = '+';
  //  value1 = NumStack.top(); NumStack.pop(); // top 
  //  value2 = NumStack.top(); NumStack.pop(); // bottom 
  //  NumStack.push(compute(Operator, value1, value2));
  //}

  std::cout << "\n\nThis is the result of computing. \n";
  std::cout << "\nNumber Stack: "; printStack(NumStack);
  std::cout << "\nOperator Stack: "; printStack(OperatorStack);
}

int main()
{
  char input;
  std::cout << "Evaluate this Operation: ";
  input = std::cin.peek();
  Evaluate(input);
}
