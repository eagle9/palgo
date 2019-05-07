//jdai code, commented and understood 
class Solution {
public:
    char *m_pData; //memory for data to store
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        if (pData) {
            m_pData = new char[strlen(pData) + 1]; //allocate memory for m_pData
            strcpy(m_pData, pData);
        }
        else {
            m_pData = NULL;
        }
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this == &object) {  //assign itself
            return *this;
        }
        
        if (m_pData) {
            delete[] m_pData;  //as specified in requirements, free up memory used
        }
        
        if (object.m_pData) {
            m_pData = new char[strlen(object.m_pData) + 1]; //allocate memory for the object after = operator
            strcpy(m_pData, object.m_pData);
        }
        else {
            m_pData = NULL;
        }
        return *this;
    }
};
