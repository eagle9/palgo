//shaun adpated from grandyang, beats 92.45%
public class Solution {
    /**
     * @param source: List[str]
     * @return: return List[str]
     */
    public List<String> removeComments(String[] source) {
        // write your code here
        List<String> res = new ArrayList<>();
        boolean blocked = false;
        String out = "";
        for (String line: source) {
            //for each char in the line
            for (int i = 0; i < line.length(); i++) {
                if (!blocked) {
                    if (i == line.length() - 1) //reach end of line
                        out += line.charAt(i);
                    else {
                        String t = line.substring(i,i+2);
                        if (t.equals("/*")) {
                            blocked = true;
                            //go to next char
                            i++;  //why i++, not i+=2? i see /*sdjfdj*/ dsjfdkjf
                            //why i++, on extra jump ,for loop already has i++
                        }else if (t.equals("//")) {
                            break;
                            //go to next line
                        }
                        else { //no comment start
                            out += line.charAt(i);
                        }
                    }
                }else {  //comment block started, blocked == true
                    //look for */ to close block
                    if (i < line.length() - 1) {
                        String t = line.substring(i, i+2);
                        if (t.equals("*/")) {
                            blocked = false;
                            i++;
                        }
                    }
                }
            }//end for each char in a line
            if (out.length() >0 && !blocked) {
                res.add(out);
                out = "";
            }
            
        }//end for line
        return res;
    }
}

