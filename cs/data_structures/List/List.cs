using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        // Creating a list of integers
        List<int> myVector = new List<int>();

        // Adding elements to the list
        myVector.Add(1);
        myVector.Add(2);
        myVector.Add(3);

        // Accessing elements
        Console.WriteLine("Element at index 1: " + myVector[1]);

        // Iterating through the list
        Console.Write("Elements in the list: ");
        foreach (var element in myVector) {
            Console.Write(element + " ");
        }
        Console.WriteLine();

        // Removing elements
        myVector.Remove(2);

        // Checking if an element exists
        if (myVector.Contains(2)) {
            Console.WriteLine("Element 2 found in the list.");
        } else {
            Console.WriteLine("Element 2 not found in the list.");
        }
    }
}