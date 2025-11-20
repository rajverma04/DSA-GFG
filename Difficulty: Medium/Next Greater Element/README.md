<h2><a href="https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1">Next Greater Element</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given an array <strong>arr[]</strong> of integers, the task is to find the <strong>next greater element</strong> for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the <strong>right </strong>which is <strong>greater</strong> than the current element.<br>If there does not exist next greater of current element, then next greater element for current element is <strong>-1</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples<br></strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 3, 2, 4]
<strong>Output:</strong> [3, 4, 4, -1]
<strong>Explanation:</strong> The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: arr[] = [6, 8, 0, 1, 3]
<strong>Output</strong>: [8, -1, 1, 3, -1]
<strong>Explanation</strong>: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: arr[] = [1, 2, 3, 5]
<strong>Output</strong>: [2, 3, 5, -1]
<strong>Explanation</strong>: For a sorted array, the next element is next greater element also except for the last element.</span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input</strong><span style="font-size: 18px;">: arr[] = [5, 4, 3, 1]
</span><strong style="font-size: 18px;">Output</strong><span style="font-size: 18px;">: [-1, -1, -1, -1]
</span><strong style="font-size: 18px;">Explanation</strong><span style="font-size: 18px;">: There is no next greater element for any of the elements in the array, so all are -1.</span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>6</sup><br>0 ≤ arr[i] ≤ 10<sup>9</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;



Step-by-Step Algorithm
Step 1: Initialize Data Structures

Create an empty stack st to store indices of elements from the array. Storing indices gives us access to both the value and the position.

Create a result vector ans of the same size as the input array, initialized with -1. This handles the default case where no greater element is found.

Step 2: Iterate Through the Array

Loop through each element in the array using its index i (from 0 to n-1).

Step 3: The Core Logic - Finding the Next Greater

While the stack is not empty AND the current element arr[i] is greater than the element at the index on the top of the stack (arr[st.top()]):

This condition means we have found the Next Greater Element for the element at st.top().

Action 1: Set ans[st.top()] = arr[i]. We assign the current element as the answer for the element at the top of the stack.

Action 2: Pop that index from the stack. Its purpose is fulfilled.

This while loop continues until the stack is empty or the current element is no longer greater than the element at the top-of-stack index.

Step 4: Push the Current Index

After resolving all possible elements for which the current element is the next greater, push the current index i onto the stack.

Why? Because we now need to find the next greater element for arr[i] itself, so we add it to the "waiting" list.

Step 5: Return the Result

After the loop completes, return the ans vector. Any indices remaining in the stack will have their corresponding values in ans as -1, which was our initial setup.
