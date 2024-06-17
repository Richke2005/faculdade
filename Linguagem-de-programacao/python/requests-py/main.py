import requests

def send_whatsapp_message(my_number_code: str, to: str, message: str) -> dict:
    """
    Sends a WhatsApp message to the specified recipient.

    Args:
    my_number_code (str): The Facebook ID of the sender's WhatsApp number.
    to (str): The recipient's WhatsApp number in the format '55' + country code + phone number.
    message (str): The text message to be sent.

    Returns:
    dict: A dictionary containing the response from the WhatsApp API.

    Raises:
    requests.exceptions.HTTPError: If the API request encounters an HTTP error.

    Example:
    ```
    response = send_whatsapp_message('286165347924405', '11947316281', 'Hello, this is a test message.')
    print(response)
    ```
    """
    url = f'https://graph.facebook.com/v19.0/{my_number_code}/messages'
    body = {
        "messaging_product": "whatsapp",
        "recipient_type": "individual",
        "to": f"55{to}",
        "type": "text",
        "text": {
            "preview_url": False,
            "body": message
        }
    }
    headers = {
        "Authorization": "Bearer EAAOJU1FBXfcBOxzJfshs5RxS6JrZAOcsuLCEhwZCKRTR4kI9QYwufP5ZCBA2RToxZAiaKtCZBodZBRV9v3XYc51bPXbIen9XUayjRyexCgBE5JqodvGoYZCZClPF3EF04ctEjfqt1wG24IIhZA4CsafvfrbUM2GMgT3YJ9uQHm7ayxusZAWBvHJMozuEuA4zTRZBQuqAK2U1VYfz5mAceLDvZCUZD"
    }
    response = requests.post(url, json=body, headers=headers)

    try:
        response.raise_for_status()
    except requests.exceptions.HTTPError as err:
        return {"error": str(err)}

    return response.json()

def main():
    message = input('Type a message: ')
    response = send_whatsapp_message('286165347924405', '11947316281', message)
    print(response)

if __name__ == '__main__':
    main()
