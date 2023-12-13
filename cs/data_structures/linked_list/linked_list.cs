using System;

public class Node
{
    public int Data;
    public Node Next;

    public Node(int data)
    {
        Data = data;
        Next = null;
    }
}

public class LinkedList
{
    private Node head;

    public LinkedList()
    {
        head = null;
    }

    // Append a new int to the start of the linked list
    public void AppendToStart(int data)
    {
        Node newNode = new Node(data);
        newNode.Next = head;
        head = newNode;
    }

    // Append a new int to the end of the linked list
    public void AppendToEnd(int data)
    {
        Node newNode = new Node(data);

        if (head == null)
        {
            head = newNode;
            return;
        }

        Node lastNode = head;
        while (lastNode.Next != null)
        {
            lastNode = lastNode.Next;
        }

        lastNode.Next = newNode;
    }

    // Remove the value at the start of the linked list
    public void RemoveFromStart()
    {
        if (head != null)
        {
            head = head.Next;
        }
    }

    // Remove the value at the end of the linked list
    public void RemoveFromEnd()
    {
        if (head == null)
        {
            return;
        }

        if (head.Next == null)
        {
            head = null;
            return;
        }

        Node currentNode = head;
        while (currentNode.Next.Next != null)
        {
            currentNode = currentNode.Next;
        }

        currentNode.Next = null;
    }

    // Display the linked list
    public void DisplayList()
    {
        Node currentNode = head;
        while (currentNode != null)
        {
            Console.Write(currentNode.Data + " ");
            currentNode = currentNode.Next;
        }

        Console.WriteLine();
    }
}

class Program
{
    static void Main()
    {
        LinkedList linkedList = new LinkedList();

        // Append to the end
        linkedList.AppendToEnd(1);
        linkedList.AppendToEnd(2);
        linkedList.AppendToEnd(3);
        linkedList.DisplayList(); // Output: 1 2 3

        // Append to the start
        linkedList.AppendToStart(0);
        linkedList.DisplayList(); // Output: 0 1 2 3

        // Remove from the start
        linkedList.RemoveFromStart();
        linkedList.DisplayList(); // Output: 1 2 3

        // Remove from the end
        linkedList.RemoveFromEnd();
        linkedList.DisplayList(); // Output: 1 2
    }
}
