import pandas as pd
sample_data = input("enter sample data: ")
sample_data = eval(sample_data)
df = pd.DataFrame(sample_data)
print(df)


                                                                                                                                                                                                                                                                                                
print(df[(df['score']>=15) & (df['score']<=20)]) 

print(df[(df['score']>=15) & (df['attempts']<=2)])


