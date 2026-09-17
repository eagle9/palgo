def miles_to_kilometers():
    # Ask the user for a number in miles
    miles = float(input("Enter the distance in miles: "))
    
    # Convert miles to kilometers (1 mile = 1.60934 kilometers)
    kilometers = miles * 1.60934
    
    # Display the result
    print(f"{miles} miles is equal to {kilometers:.2f} kilometers.")

# Call the function
miles_to_kilometers()
