import cv2
import easyocr
import matplotlib.pyplot as plt

def preprocess_image(image_path, output_path):
    image = cv2.imread(image_path)

    rotated_image = cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE)

    gray = cv2.cvtColor(rotated_image, cv2.COLOR_BGR2GRAY)

    _, thresholded = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    cv2.imwrite(output_path, thresholded)
    """
    plt.imshow(thresholded, cmap='gray', vmin=0,vmax=255)
    plt.show()
    """
    return thresholded
    
def extract_text(image_path):
    reader = easyocr.Reader(['en'])
    result = reader.readtext(image_path, paragraph=False, allowlist="0123456789+-x*/()=", width_ths=1.0)
    text = ' '.join([bbox[1] for bbox in result])
    #Calcular punt de partida per escriure el resultat
    textbox_coordinates=[item[0] for item in result]
    start_coordinates=[item[1] for item in textbox_coordinates]

    return text, start_coordinates

def filter_expression(expression):
    """
    Filters out everything from the strings that isn't a number or an operator (+, -, *, /).

    Parameters:
    - expressions: List of strings containing mathematical expressions.

    Returns:
    - A list of filtered expressions containing only numbers and operators.
    """
    # Define valid characters (numbers and operators)
    valid_chars = "0123456789+-*/"

    # Build a new string with only valid characters
    filtered_expression = ''.join(char for char in expression if char in valid_chars)
    return filtered_expression

def resolve_math_expression(expression):
    try:
        result = eval(expression)
        return result
    except:
        return "Error"


