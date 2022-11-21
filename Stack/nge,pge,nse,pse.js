/*
REFERENCE : https://leetcode.com/discuss/study-guide/2347639/A-comprehensive-guide-and-template-for-monotonic-stack-based-problems


NOTE:

Problem	Stack:             Type	Operator in while loop:	     Assignment:               Position:
next greater	              decreasing (equal allowed)	     stackTop < current	    inside while loop
previous greater	          decreasing (strict)	             stackTop <= current	  outside while loop
next smaller	              increasing (equal allowed)	     stack Top > current	  inside while loop
previous smaller	          increasing (strict)	             stackTop >= current	  outside while loop

code template:
stack=[]   
next=[]
prev=[]
for each ele in array:
  while loop(!stack.empty() && v[s.top()] *operator* v[i]) :  -->here you will have equal to (<= or >=) mostly.
    next array[s.top] =i         -->the next array like nge and nse will be updated here.
    s.pop()
  if(s.size()) prev array[i]=s.top()    --> prev array like pge and ple will be updated here
                                            note in while block assignment was array[s.top] =i while
                                            outside of while bloack its array[i]=s.top().
  s.push(i)


*/





function findNextGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize nextGreater array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let nextGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is STRICTLY SMALLER than the current element
    // This means, the stack will always be monotonic non increasing (type 4)
    while (stack.length && arr[stack.at(-1)] < arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // as given in the condition of the while loop above,
      // nextGreater element of stackTop is the element at index i
      nextGreater[stackTop] = i;
    }
    
    // push the current element
    stack.push(i);
  }
  return nextGreater;
}



function findPreviousGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousGreater array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
     // while loop runs until the stack is not empty AND
     // the element represented by stack top is SMALLER OR EQUAL to the current element
     // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
     // so equal elements will never stay in the stack (definition of strictly decreasing stack)
    while (stack.length && arr[stack.at(-1)] <= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
    }
    
    // after the while loop, only the elements which are greater than the current element are left in stack
    // this means we can confidentally decide the previous greater element of the current element i, that's stack top
    if (stack.length) {
      previousGreater[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return previousGreater;
}

function findNextAndPreviousGreaterIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousGreater and nextGreater arrays
  let previousGreater = new Array(arr.length).fill(-1);
  let nextGreater = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
     // while loop runs until the stack is not empty AND
     // the element represented by stack top is SMALLER OR EQUAL to the current element
     // This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
     // so equal elements will never stay in the stack (definition of strictly decreasing stack)
    while (stack.length && arr[stack.at(-1)] <= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // This is the only additional line added to the last approach
      // decides the next greater element for the index popped out from stack
      nextGreater[stackTop] = i;
    }
    
    // after the while loop, only the elements which are greater than the current element are left in stack
    // this means we can confidentally decide the previous greater element of the current element i, that's stack top
    if (stack.length) {
      previousGreater[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return [previousGreater, nextGreater];
}

function findNextSmallerIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize nextGreater array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let nextSmaller = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is STRICTLY LARGER than the current element
    // This means, the stack will always be monotonic non decreasing (type 2)
    while (stack.length && arr[stack.at(-1)] > arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // as given in the condition of the while loop above,
      // nextSmaller element of stackTop is the element at index i
      nextSmaller[stackTop] = i;
    }
    
    // push the current element
    stack.push(i);
  }
  return nextSmaller;
}

function findNextSmallerIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousSmaller array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousSmaller = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is LARGER OR EQUAL to the current element
    // This means, the stack will always be monotonic strictly increasing (type 1)
    while (stack.length && arr[stack.at(-1)] >= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
    }
    
    // this is the additional bit here
    if (stack.length) {
      // the index at the stack top refers to the previous smaller element for `i`th index
      previousSmaller[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return previousSmaller;
}

function findNextSmallerIndexes(arr) {
  // initialize an empty stack
  let stack = [];
  
  // initialize previousSmaller array, this array hold the output
  // initialize all the elements are -1 (invalid value)
  let previousSmaller = new Array(arr.length).fill(-1);
  
  // iterate through all the elements of the array
  for (let i = 0; i < arr.length; i++) {
  
    // while loop runs until the stack is not empty AND
    // the element represented by stack top is LARGER OR EQUAL to the current element
    // This means, the stack will always be monotonic strictly increasing (type 1)
    while (stack.length && arr[stack.at(-1)] >= arr[i]) {
    
      // pop out the top of the stack, it represents the index of the item
      let stackTop = stack.pop();
      
      // as given in the condition of the while loop above,
      // nextSmaller element of stackTop is the element at index i
      nextSmaller[stackTop] = i;
    }
    
    // this is the additional bit here
    if (stack.length) {
      // the index at the stack top refers to the previous smaller element for `i`th index
      previousSmaller[i] = stack.at(-1);
    }
    
    // push the current element
    stack.push(i);
  }
  return [nextSmaller, previousSmaller];
}