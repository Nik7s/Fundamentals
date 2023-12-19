using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        Dictionary<string, int> myDictionary = new Dictionary<string, int>();

        // Insert key-value pairs
        myDictionary["One"] = 1;
        myDictionary["Two"] = 2;
        myDictionary["Three"] = 3;

        // Access values
        Console.WriteLine("Value for key 'Two': " + myDictionary["Two"]);

        // Check if a key exists
        if (myDictionary.TryGetValue("Four", out int value)) {
            Console.WriteLine("Value for key 'Four': " + value);
        } else {
            Console.WriteLine("Key 'Four' not found.");
        }
    }
}