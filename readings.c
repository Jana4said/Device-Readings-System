#include <stdio.h>
#include <string.h>
#include "readings.h"


int init_device(struct Device *device, char *name, float max, float min)
{
    // Early return if parameters are invalid
    if (!device || !name)
    {
        return ERR_INVALID_PARAMETER;
    }

    // Use strncpy for safe string copy
    strncpy(device->name, name, MAX_STR - 1);
    device->name[MAX_STR - 1] = '\0';

    // Assign the max and min 
    device->max = max;
    device->min = min;

    return ERR_OK;
}


int init_reading(struct Reading *reading, struct Device *device, float value, char const *room)
{
    // Valid inputs
    if (!(reading && device && room))
    {
        return ERR_INVALID_PARAMETER;
    }

    //  valid range 
    int validation_result = valid_device_reading(device, value);
    if (validation_result != ERR_OK)
    {
        return validation_result;
    }

    //  to reading fields
    reading->device = device;
    reading->value = value;


    strncpy(reading->room, room, MAX_STR - 1);
    reading->room[MAX_STR - 1] = '\0';

    return ERR_OK;
}


int valid_device_reading(struct Device *device, float value)
{
    // device  is valid
    if (!device)
    {
        return ERR_INVALID_PARAMETER;
    }

    // Check the range 
    return (value >= device->min && value <= device->max) ? ERR_OK : ERR_INVALID_VALUE;
}


int init_reading_collection(struct ReadingCollection *readings)
{
    if (!readings)
    {
        return ERR_INVALID_PARAMETER;
    }

    readings->size = 0; // Start w empty collection
    return ERR_OK;
}

int add_reading(struct ReadingCollection *readings, struct Reading reading)
{
    // if there's  a space 
    if (readings->size >= MAX_READINGS)
    {
        return ERR_MAX_CAPACITY;
    }

    int pos = readings->size;
    while (pos > 0 && strcmp(readings->elements[pos - 1].room, reading.room) > 0)
    {
        readings->elements[pos] = readings->elements[pos - 1];
        pos--;
    }

    // Place the new reading 
    readings->elements[pos] = reading;
    readings->size++;

    return ERR_OK;
}


int print_reading(const struct Reading *reading)
{
    // Check 
    if (!(reading && reading->device)) {
        return ERR_INVALID_PARAMETER;
    }

    printf("Room: %s, Device: %s, Value: %.2f\n", reading->room, reading->device->name, reading->value);
    return ERR_OK;
}


int print_reading_collection(struct ReadingCollection *readings)
{
    //check
    if (!readings)
    {
        return ERR_INVALID_PARAMETER;
    }

    for (int i = 0; i < readings->size; i++)
    {
        print_reading(&readings->elements[i]);
    }

    return ERR_OK;
}
//side quest function
int remove_duplicates(struct ReadingCollection *readings)
{
    if (!readings || readings->size == 0)
    {
        return ERR_INVALID_PARAMETER;
    }

    int unique_index = 0;
    for (int i = 1; i < readings->size; i++)
    {
        if (strcmp(readings->elements[i].room, readings->elements[unique_index].room) != 0 ||
            readings->elements[i].device != readings->elements[unique_index].device)
        {
            readings->elements[++unique_index] = readings->elements[i];
        }
    }

    // Update 
    readings->size = unique_index + 1;
    return ERR_OK;
}
