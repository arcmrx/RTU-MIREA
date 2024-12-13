package Practice15;

import java.io.*;
import java.net.*;
import java.util.*;

public class CalculatorHttpServer {
    private static final int PORT = 44;
    private static final String STUDENT_NAME = "Volkov-A-V";
    private static final String STUDENT_ID = "IKBO-66-23";

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Calculator HTTP Server запущен на порту " + PORT);
            while (true) {
                try (Socket clientSocket = serverSocket.accept()) {
                    handleClient(clientSocket);
                }
            }
        } catch (IOException e) {
            System.err.println("Ошибка запуска сервера: " + e.getMessage());
        }
    }

    private static void handleClient(Socket clientSocket) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream());

        String line = in.readLine();
        if (line == null)
            return;

        String[] requestParts = line.split(" ");
        String method = requestParts[0];
        String path = requestParts[1];

        if (method.equals("GET") && path.startsWith("/calculate")) {
            handleCalculate(path, out);
        } else {
            handleNotFound(out);
        }

        out.flush();
    }

    private static void handleCalculate(String path, PrintWriter out) {
        try {
            Map<String, String> params = extractParams(path);
            String aParam = params.get("a");
            String bParam = params.get("b");
            String opParam = params.get("op");

            if (aParam != null && bParam != null && opParam != null) {
                double a = Double.parseDouble(aParam);
                double b = Double.parseDouble(bParam);
                String result = calculate(a, b, opParam);
                sendHttpResponse(out, 200, "<html><body><h1>Result: " + result + "</h1><p>" + STUDENT_NAME + " ("
                        + STUDENT_ID + ")</p></body></html>");
            } else {
                sendHttpResponse(out, 400,
                        "<html><body><h1>400 Bad Request</h1><p>Missing parameters (a, b, or op)</p></body></html>");
            }
        } catch (NumberFormatException e) {
            sendHttpResponse(out, 400,
                    "<html><body><h1>400 Bad Request</h1><p>Invalid number format</p></body></html>");
        }
    }

    private static Map<String, String> extractParams(String path) {
        Map<String, String> params = new HashMap<>();
        String query = path.split("\\?")[1];
        String[] pairs = query.split("&");
        for (String pair : pairs) {
            String[] keyValue = pair.split("=");
            if (keyValue.length == 2) {
                params.put(keyValue[0], keyValue[1]);
            }
        }
        return params;
    }

    private static String calculate(double a, double b, String op) {
        switch (op) {
            case "+":
                return String.valueOf(a + b);
            case "-":
                return String.valueOf(a - b);
            case "*":
                return String.valueOf(a * b);
            case "/":
                if (b == 0) {
                    return "Error: Division by zero";
                }
                return String.valueOf(a / b);
            default:
                return "Error: Unsupported operation";
        }
    }

    private static void sendHttpResponse(PrintWriter out, int statusCode, String body) {
        out.println("HTTP/1.1 " + statusCode + " OK");
        out.println("Content-Type: text/html");
        out.println("Content-Length: " + body.length());
        out.println();
        out.println(body);
    }

    private static void handleNotFound(PrintWriter out) {
        sendHttpResponse(out, 404, "<html><body><h1>404 Not Found</h1></body></html>");
    }
}