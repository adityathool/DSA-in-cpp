tasks = ["do homework", "study dsa", "wash clothes","fresh up"]
completed_tasks = []
incomplete_tasks = []
completed_tasks.append(tasks[0])
completed_tasks.append(tasks[2])
for i in tasks:
    if i not in completed_tasks:
        incomplete_tasks.append(i)

print("The tasks you have completed is/are: ",completed_tasks,"\n")
print("The tasks you werent complete is/are",incomplete_tasks)

