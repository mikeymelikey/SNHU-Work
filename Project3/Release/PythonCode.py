#Michael Ditullio 10/17/21
import re
import string
import time
import operator
import os
import sys


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v


def word_frequency():
    #This text file contains a list of words. Count the frequency of the words and print the result to the screen.
    #The output is in descending order.
    #The output is in the format:
    #word1: count1
    #word2: count2
    #...
    #wordn: countn
    
    __location__ = os.path.realpath(
        os.path.join(os.getcwd(), os.path.dirname(__file__)))

    #Open the file
    f = open(os.path.join(__location__, 'veggie.txt'), 'r')

    #Pause for 2 seconds
    print("Generating...")
    time.sleep(2)
    

    #read the file
    text = f.read()
    #split the file into a list of words
    words = text.split()
    #create a dictionary to store the words and their counts
    word_count = {}
    #loop through the list of words
    for word in words:
        #if the word is not in the dictionary, add it and set the count to 1
        if word not in word_count:
            word_count[word] = 1
        #if the word is in the dictionary, increment the count by 1
        else:
            word_count[word] += 1
    #sort the dictionary by value
    sorted_word_count = sorted(word_count.items(), key=operator.itemgetter(1), reverse=True)
    #print the sorted dictionary
    for word in sorted_word_count:
        print(word[0] + ': ' + str(word[1]))

def word_frequency_one(word):
    __location__ = os.path.realpath(
        os.path.join(os.getcwd(), os.path.dirname(__file__)))

    #Open the file
    f = open(os.path.join(__location__, 'veggie.txt'), 'r')
    #read the file
    text = f.read()
    #split the file into a list of words
    words = text.split()
    #Capitalize the first letter
    word = word.capitalize()
    #count the number of times the word appears in the list
    count = words.count(word)
    #close the file
    f.close()
    #return the count
    return count

def word_frequency_proportional():
    #This text file contains a list of words. Count the frequency of the words and write to a new file named frequency.dat
    #The output is in descending order.
    #The output is in the format:
    #word1: *
    #word2: **
    #...
    #wordn: * n times
    #where * is the number of times the word appears in the text file.
    
    __location__ = os.path.realpath(
        os.path.join(os.getcwd(), os.path.dirname(__file__)))

    #Open the file
    f = open(os.path.join(__location__, 'veggie.txt'), 'r')

    #Pause for 2 seconds
    print("Generating...")
    time.sleep(2)
    

    #read the file
    text = f.read()
    #split the file into a list of words
    words = text.split()
    #create a dictionary to store the words and their counts
    word_count = {}
    #loop through the list of words
    for word in words:
        #if the word is not in the dictionary, add it and set the count to 1
        if word not in word_count:
            word_count[word] = 1
        #if the word is in the dictionary, increment the count by 1
        else:
            word_count[word] += 1
    #sort the dictionary by value
    sorted_word_count = sorted(word_count.items(), key=operator.itemgetter(1), reverse=True)
    __location__ = os.path.realpath(
        os.path.join(os.getcwd(), os.path.dirname(__file__)))

    #Open the file
    f = open(os.path.join(__location__, 'frequency.dat'), 'w')

    #loop through the sorted dictionary
    for word in sorted_word_count:
        #write the word and its count to the file
        f.write(word[0] + ': ' + str(word[1]*'*'))
        #write a newline character after each word
        f.write('\n')
    #close the file
    f.close()
    #print a message to the user
    print("Done! The file is in Project3/release/")

