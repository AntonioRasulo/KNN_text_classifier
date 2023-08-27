# KNN_text_classifier
C++ code that calculate several distances between a document (document under test) and a set of document (training set) to understand the typology of the document under test.<br />
Pass as arguments:<br />
-set : path to training set<br />
-input : filepath to the document under test<br />
-output : path to the output folder where to store the output csv files containing the results<br />
-k : k value to apply to the KNN model<br />
-p : p value to apply to the Minkowski classifier, if provided 0 p will assume the value 1<br />
Example:<br />
main.exe -set \<trainingSetPath\> -input \<filepathToDocUnderTest\> -output \<outputFolderPath\> -k 3 -p 5