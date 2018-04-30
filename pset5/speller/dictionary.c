#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define HASH_SIZE 2000


typedef struct node
{
    
    char word[LENGTH+1];
    struct node *next;
}
node;

node* hashtable[HASH_SIZE];

int count_of_words=0;


int hash_function(const char* word);
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    int word_length = strlen(word);
    char lower_word[LENGTH+1];
    
    // Convert word to lowercase to accurately compare to hash table.
    for (int i = 0; i < word_length; i++)
    {
        // If character is uppercase, make it lowercase.
        if(isupper(word[i]))
        {
            lower_word[i] = tolower(word[i]) ;
        }
        // Otherwise it's already lowercase or it's not a letter.
        else
        {
            lower_word[i] = word[i];
        }
    } 
    
    lower_word[word_length] = '\0';
    
    int bucket = hash_function(lower_word);
    
    node * cursor = hashtable[bucket];
    while(cursor!=NULL)
    {
        if (strcmp(lower_word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    
    // Initialize each value in hash table to NULL.
    for(int i = 0; i < HASH_SIZE; i++)
    {
        hashtable[i] = NULL;
    } 
    
    //Open the File for reading purpose
    
    FILE* dict = fopen(dictionary, "r");
    if(dict==NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }
    
    char buffer[LENGTH+1];
    
    while(fscanf(dict,"%s", buffer)> 0)
    {
        node *new_node = malloc(sizeof(node));
        
        new_node->next = NULL;
        
        strcpy(new_node->word,buffer);
        //int bucket=hash_function(buffer);
        int bucket = hash_function(new_node->word);
        
        if(hashtable[bucket]==NULL)
        {
            hashtable[bucket]=new_node;
        }
         else
        {
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;
        }
        count_of_words++;
    }
    
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return count_of_words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TO
    
    for (int i = 0; i < HASH_SIZE;i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {

            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    } 
    return true;
}



//hashfunction ..............................................//
int hash_function(const char* word)
{
    int sum = 0;
    int word_length = strlen(word);

    for (int i = 0; i < word_length; i++)
    {
        sum += word[i];
    }
    
    int bucket = sum % HASH_SIZE;
    return bucket;
}