from http.server import BaseHTTPRequestHandler, HTTPServer

class WebServer(BaseHTTPRequestHandler):

  def do_GET(self):
        # Send response status code
        self.send_response(200)

        # Send headers
        self.send_header('Content-type','text/html')
        self.end_headers()

        # Send message back to client
        data = ''
        with open('index.html') as f:
            line = f.readline()
            while line:
                data = data + line
                line = f.readline()
        # Write content as utf-8 data
        self.wfile.write(bytes(data, "utf8"))
        return
